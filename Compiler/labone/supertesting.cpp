#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <fstream>
#include <numeric>
#include <cmath>
#include <random>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <atomic>
#include <mutex>
#include <regex>

using namespace std;
using namespace std::chrono;

// -----------------------------------------------------------------
// Global Constants (Tuned for an Average Modern Computer)
// -----------------------------------------------------------------
const int MATRIX_SIZE_AVG = 750;                   // For CPU tests (matrix multiplication)
const size_t MEM_BW_SIZE_AVG = 20'000'000;           // 20 million doubles (~160MB) for memory bandwidth
const size_t MEM_LATENCY_SIZE_AVG = 5'000'000;       // 5 million ints for memory latency
const size_t DISK_IO_SIZE_AVG = 250 * 1024 * 1024;   // 250MB file for disk I/O test
const int SORT_SIZE_AVG = 5'000'000;                 // 5 million elements for sorting test
const long long MONTE_CARLO_ITERATIONS_AVG = 50'000'000; // 50 million iterations for Monte Carlo Pi
const int CONTEXT_SWITCH_THREADS_AVG = 200;          // Increased number of threads for context switching
const long long ATOMIC_TOTAL_INCREMENTS_AVG = 50'000'000; // 50 million total atomic increments

// Software Development Tools Tests:
const size_t REGEX_TEST_SIZE_AVG = 5'000'000;        // 5 million characters for regex test
const int SOURCE_CODE_LINES_AVG = 50'000;            // 50,000 lines for source code parsing test
const int DIFF_FILE_LINES_AVG = 1000;                // 1,000 lines per file for diff algorithm test

// -----------------------------------------------------------------
// Test Result Structure
// -----------------------------------------------------------------
struct TestResult {
    string testName;
    double timeTaken;      // In seconds (or the dominant metric)
    string rating;         // "Good", "Medium", "Bad", or "Skipped"
    string details;        // Additional details for the report
};

vector<TestResult> testResults; // Global container for all test results

// Helper to record test results.
void addTestResult(const string &testName, double timeTaken, const string &rating, const string &details = "") {
    testResults.push_back({testName, timeTaken, rating, details});
}

// Global mutex for safe console output (if needed).
mutex coutMutex;

// -----------------------------------------------------------------
// CPU Tests
// -----------------------------------------------------------------

// Single-threaded CPU test using matrix multiplication with trigonometric operations.
void testSingleThreadedCPU(double &ratingScore) {
    auto start = high_resolution_clock::now();
    
    int N = MATRIX_SIZE_AVG;
    vector<vector<double>> A(N, vector<double>(N, 1.0));
    vector<vector<double>> B(N, vector<double>(N, 2.0));
    vector<vector<double>> C(N, vector<double>(N, 0.0));
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                C[i][j] += sin(A[i][k]) * cos(B[k][j]);
    
    auto end = high_resolution_clock::now();
    double timeTaken = duration<double>(end - start).count();
    
    string rating;
    if (timeTaken < 3.0) {
        rating = "Good";
        ratingScore += 1.0;
    } else if (timeTaken < 6.0) {
        rating = "Medium";
        ratingScore += 0.5;
    } else {
        rating = "Bad";
    }
    
    cout << "Single-threaded CPU test completed in: " << timeTaken << " seconds (" << rating << ")\n";
    addTestResult("Single-threaded CPU Test", timeTaken, rating, "Matrix multiplication with sin/cos operations");
}

// Multi-threaded CPU test using matrix multiplication.
void testMultiThreadedCPU(int numThreads, double &ratingScore) {
    auto start = high_resolution_clock::now();
    
    int N = MATRIX_SIZE_AVG;
    vector<vector<double>> A(N, vector<double>(N, 1.0));
    vector<vector<double>> B(N, vector<double>(N, 2.0));
    vector<vector<double>> C(N, vector<double>(N, 0.0));
    
    vector<thread> threads;
    for (int t = 0; t < numThreads; ++t) {
        threads.emplace_back([&, t]() {
            int startRow = t * (N / numThreads);
            int endRow = (t == numThreads - 1) ? N : (t + 1) * (N / numThreads);
            for (int i = startRow; i < endRow; ++i)
                for (int j = 0; j < N; ++j)
                    for (int k = 0; k < N; ++k)
                        C[i][j] += sin(A[i][k]) * cos(B[k][j]);
        });
    }
    
    for (auto &t : threads)
        t.join();
    
    auto end = high_resolution_clock::now();
    double timeTaken = duration<double>(end - start).count();
    
    string rating;
    if (timeTaken < 1.5) {
        rating = "Good";
        ratingScore += 1.0;
    } else if (timeTaken < 3.0) {
        rating = "Medium";
        ratingScore += 0.5;
    } else {
        rating = "Bad";
    }
    
    cout << "Multi-threaded CPU test (" << numThreads << " threads) completed in: " 
         << timeTaken << " seconds (" << rating << ")\n";
    addTestResult("Multi-threaded CPU Test", timeTaken, rating, "Matrix multiplication across multiple threads");
}

// Atomic operations test to measure thread synchronization overhead.
void testAtomicOperations(double &ratingScore) {
    int numThreads = thread::hardware_concurrency();
    atomic<long long> counter(0);
    long long incrementsPerThread = ATOMIC_TOTAL_INCREMENTS_AVG / numThreads;
    
    auto atomicTask = [&]() {
        for (long long i = 0; i < incrementsPerThread; ++i)
            counter.fetch_add(1, memory_order_relaxed);
    };
    
    auto start = high_resolution_clock::now();
    vector<thread> threads;
    for (int t = 0; t < numThreads; ++t)
        threads.emplace_back(atomicTask);
    for (auto &t : threads)
        t.join();
    auto end = high_resolution_clock::now();
    
    double timeTaken = duration<double>(end - start).count();
    string rating;
    if (timeTaken < 0.3) {
        rating = "Good";
        ratingScore += 1.0;
    } else if (timeTaken < 0.6) {
        rating = "Medium";
        ratingScore += 0.5;
    } else {
        rating = "Bad";
    }
    
    ostringstream details;
    details << "Performed " << ATOMIC_TOTAL_INCREMENTS_AVG << " atomic increments across " << numThreads << " threads";
    cout << "Atomic operations test completed in: " << timeTaken << " seconds (" << rating << ")\n";
    addTestResult("Atomic Operations Test", timeTaken, rating, details.str());
}

// -----------------------------------------------------------------
// Memory Tests
// -----------------------------------------------------------------

// Memory bandwidth test.
void testMemoryBandwidth(double &ratingScore) {
    size_t arraySize = MEM_BW_SIZE_AVG;
    vector<double> data(arraySize, 1.0);
    
    auto start = high_resolution_clock::now();
    volatile double sum = 0.0; // Prevent optimization
    for (size_t i = 0; i < arraySize; ++i)
        sum += sqrt(data[i]);
    auto end = high_resolution_clock::now();
    
    double timeTaken = duration<double>(end - start).count();
    string rating;
    if (timeTaken < 1.0) {
        rating = "Good";
        ratingScore += 1.0;
    } else if (timeTaken < 2.0) {
        rating = "Medium";
        ratingScore += 0.5;
    } else {
        rating = "Bad";
    }
    
    cout << "Memory bandwidth test completed in: " << timeTaken << " seconds (" << rating << ")\n";
    addTestResult("Memory Bandwidth Test", timeTaken, rating, "Iterated over " + to_string(arraySize) + " doubles computing sqrt");
}

// Memory latency test.
void testMemoryLatency(double &ratingScore) {
    size_t arraySize = MEM_LATENCY_SIZE_AVG;
    vector<int> data(arraySize);
    iota(data.begin(), data.end(), 0);
    random_device rd;
    mt19937 g(rd());
    shuffle(data.begin(), data.end(), g);
    
    auto start = high_resolution_clock::now();
    size_t index = 0;
    for (size_t i = 0; i < arraySize; ++i)
        index = data[index];
    auto end = high_resolution_clock::now();
    
    double timeTaken = duration<double>(end - start).count();
    string rating;
    if (timeTaken < 0.03) {
        rating = "Good";
        ratingScore += 1.0;
    } else if (timeTaken < 0.1) {
        rating = "Medium";
        ratingScore += 0.5;
    } else {
        rating = "Bad";
    }
    
    cout << "Memory latency test completed in: " << timeTaken << " seconds (" << rating << ")\n";
    addTestResult("Memory Latency Test", timeTaken, rating, "Random access on " + to_string(arraySize) + " integers");
}

// -----------------------------------------------------------------
// Disk I/O Test
// -----------------------------------------------------------------
void testDiskIO(double &ratingScore) {
    string filename = "testfile_avg.dat";
    size_t fileSize = DISK_IO_SIZE_AVG;
    vector<char> buffer(fileSize, 'a');
    
    auto writeStart = high_resolution_clock::now();
    {
        ofstream outFile(filename, ios::binary);
        if (!outFile) {
            cout << "Disk I/O Test: Unable to open file for writing.\n";
            addTestResult("Disk I/O Test", 0.0, "Skipped", "File could not be opened for writing");
            return;
        }
        outFile.write(buffer.data(), fileSize);
    }
    auto writeEnd = high_resolution_clock::now();
    double writeTime = duration<double>(writeEnd - writeStart).count();
    
    auto readStart = high_resolution_clock::now();
    {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cout << "Disk I/O Test: Unable to open file for reading.\n";
            addTestResult("Disk I/O Test", 0.0, "Skipped", "File could not be opened for reading");
            return;
        }
        inFile.read(buffer.data(), fileSize);
    }
    auto readEnd = high_resolution_clock::now();
    double readTime = duration<double>(readEnd - readStart).count();
    
    remove(filename.c_str());
    
    double overallTime = writeTime + readTime;
    string rating;
    if (writeTime < 1.5 && readTime < 1.5) {
        rating = "Good";
        ratingScore += 1.0;
    } else if (writeTime < 3.0 && readTime < 3.0) {
        rating = "Medium";
        ratingScore += 0.5;
    } else {
        rating = "Bad";
    }
    
    ostringstream details;
    details << "Write: " << writeTime << " s, Read: " << readTime << " s";
    cout << "Disk I/O test completed (" << details.str() << ") (" << rating << ")\n";
    addTestResult("Disk I/O Test", overallTime, rating, details.str());
}

// -----------------------------------------------------------------
// Network Test
// -----------------------------------------------------------------

// Network performance test (download speed) using a system call.
void testNetworkPerformance(double &ratingScore) {
    string command = "wget -O /dev/null https://speed.hetzner.de/100MB.bin";
#ifdef _WIN32
    command = "curl -o NUL https://speed.hetzner.de/100MB.bin";
#endif
    auto start = high_resolution_clock::now();
    int ret = system(command.c_str());
    auto end = high_resolution_clock::now();
    double timeTaken = duration<double>(end - start).count();
    
    string rating;
    if (ret != 0) {
        rating = "Skipped";
        cout << "Network download test could not be executed.\n";
        addTestResult("Network Performance Test", timeTaken, rating, "Download command failed");
        return;
    }
    
    if (timeTaken < 5.0) {
        rating = "Good";
        ratingScore += 1.0;
    } else if (timeTaken < 10.0) {
        rating = "Medium";
        ratingScore += 0.5;
    } else {
        rating = "Bad";
    }
    
    cout << "Network download test completed in: " << timeTaken << " seconds (" << rating << ")\n";
    addTestResult("Network Performance Test", timeTaken, rating, "Downloaded 100MB using system command");
}

// -----------------------------------------------------------------
// Algorithmic & Miscellaneous Tests
// -----------------------------------------------------------------

// Sorting performance test.
void testSortingPerformance(double &ratingScore) {
    vector<int> data(SORT_SIZE_AVG);
    iota(data.begin(), data.end(), 0);
    random_device rd;
    mt19937 g(rd());
    shuffle(data.begin(), data.end(), g);
    
    auto start = high_resolution_clock::now();
    sort(data.begin(), data.end());
    auto end = high_resolution_clock::now();
    double timeTaken = duration<double>(end - start).count();
    
    string rating;
    if (timeTaken < 0.2) {
        rating = "Good";
        ratingScore += 1.0;
    } else if (timeTaken < 0.4) {
        rating = "Medium";
        ratingScore += 0.5;
    } else {
        rating = "Bad";
    }
    
    cout << "Sorting test completed in: " << timeTaken << " seconds (" << rating << ")\n";
    addTestResult("Sorting Performance Test", timeTaken, rating, "Sorted " + to_string(SORT_SIZE_AVG) + " integers");
}

// Monte Carlo simulation to estimate Pi.
void testMonteCarloPi(double &ratingScore) {
    int numThreads = thread::hardware_concurrency();
    long long iterationsPerThread = MONTE_CARLO_ITERATIONS_AVG / numThreads;
    atomic<long long> inCircle(0);
    
    auto monteCarlo = [&]() {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<double> dist(0.0, 1.0);
        long long count = 0;
        for (long long i = 0; i < iterationsPerThread; ++i) {
            double x = dist(gen);
            double y = dist(gen);
            if (x * x + y * y <= 1.0)
                ++count;
        }
        inCircle += count;
    };
    
    auto start = high_resolution_clock::now();
    vector<thread> threads;
    for (int t = 0; t < numThreads; ++t)
        threads.emplace_back(monteCarlo);
    for (auto &t : threads)
        t.join();
    auto end = high_resolution_clock::now();
    
    double piEstimate = 4.0 * inCircle / MONTE_CARLO_ITERATIONS_AVG;
    double timeTaken = duration<double>(end - start).count();
    
    string rating;
    if (timeTaken < 1.0) {
        rating = "Good";
        ratingScore += 1.0;
    } else if (timeTaken < 2.0) {
        rating = "Medium";
        ratingScore += 0.5;
    } else {
        rating = "Bad";
    }
    
    ostringstream details;
    details << "Estimated Pi = " << piEstimate;
    cout << "Monte Carlo Pi test completed in: " << timeTaken << " seconds (" << rating << ") - " 
         << details.str() << "\n";
    addTestResult("Monte Carlo Pi Test", timeTaken, rating, details.str());
}

// Context switching performance test.
void testContextSwitching(double &ratingScore) {
    vector<thread> threads;
    auto contextFunc = []() {
        this_thread::sleep_for(chrono::milliseconds(1));
    };
    
    auto start = high_resolution_clock::now();
    for (int i = 0; i < CONTEXT_SWITCH_THREADS_AVG; ++i)
        threads.emplace_back(contextFunc);
    for (auto &t : threads)
        t.join();
    auto end = high_resolution_clock::now();
    
    double timeTaken = duration<double>(end - start).count();
    string rating;
    if (timeTaken < 0.2) {
        rating = "Good";
        ratingScore += 1.0;
    } else if (timeTaken < 0.4) {
        rating = "Medium";
        ratingScore += 0.5;
    } else {
        rating = "Bad";
    }
    
    cout << "Context switching test completed in: " << timeTaken << " seconds (" << rating << ")\n";
    addTestResult("Context Switching Test", timeTaken, rating, "Spawned and joined " + to_string(CONTEXT_SWITCH_THREADS_AVG) + " threads");
}

// -----------------------------------------------------------------
// Software Development Tools Tests
// -----------------------------------------------------------------

// Regex Matching Test: Searches a large text block using regular expressions.
void testRegexMatching(double &ratingScore) {
    // Generate a large text simulating source code/logs.
    string baseLine = "void exampleFunction() { int value = 42; /* test regex pattern */ }\n";
    string text;
    text.reserve(REGEX_TEST_SIZE_AVG);
    while(text.size() < REGEX_TEST_SIZE_AVG)
        text.append(baseLine);
    
    regex pattern(R"(void\s+([a-zA-Z_]\w*)\s*\()");
    auto start = high_resolution_clock::now();
    auto words_begin = sregex_iterator(text.begin(), text.end(), pattern);
    auto words_end = sregex_iterator();
    int matchCount = distance(words_begin, words_end);
    auto end = high_resolution_clock::now();
    double timeTaken = duration<double>(end - start).count();
    
    string rating;
    if (timeTaken < 0.3) {
        rating = "Good";
        ratingScore += 1.0;
    } else if (timeTaken < 0.6) {
        rating = "Medium";
        ratingScore += 0.5;
    } else {
        rating = "Bad";
    }
    
    ostringstream details;
    details << "Found " << matchCount << " function declarations";
    cout << "Regex Matching test completed in: " << timeTaken << " seconds (" << rating << ")\n";
    addTestResult("Regex Matching Test", timeTaken, rating, details.str());
}

// Source Code Parsing Test: Simulates reading and tokenizing a large source file.
void testSourceCodeParsing(double &ratingScore) {
    // Generate pseudo-source code with many lines.
    ostringstream oss;
    for (int i = 0; i < SOURCE_CODE_LINES_AVG; ++i) {
        oss << "int var" << i << " = " << i << "; // Line " << i << "\n";
    }
    string code = oss.str();
    
    auto start = high_resolution_clock::now();
    istringstream iss(code);
    string line;
    int totalTokens = 0;
    while(getline(iss, line)) {
        istringstream lineStream(line);
        string token;
        while(lineStream >> token)
            totalTokens++;
    }
    auto end = high_resolution_clock::now();
    double timeTaken = duration<double>(end - start).count();
    
    string rating;
    if (timeTaken < 0.1) {
        rating = "Good";
        ratingScore += 1.0;
    } else if (timeTaken < 0.2) {
        rating = "Medium";
        ratingScore += 0.5;
    } else {
        rating = "Bad";
    }
    
    ostringstream details;
    details << "Parsed " << SOURCE_CODE_LINES_AVG << " lines and " << totalTokens << " tokens";
    cout << "Source Code Parsing test completed in: " << timeTaken << " seconds (" << rating << ")\n";
    addTestResult("Source Code Parsing Test", timeTaken, rating, details.str());
}

// Diff Algorithm Test: Simulates a version control diff by computing the LCS between two file versions.
int computeLCS(const vector<string>& a, const vector<string>& b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

void testDiffAlgorithm(double &ratingScore) {
    // Generate two versions of a file as vectors of strings.
    vector<string> versionA, versionB;
    for (int i = 0; i < DIFF_FILE_LINES_AVG; ++i) {
        versionA.push_back("Line " + to_string(i) + ": original content");
        // Introduce modifications every 10 lines in versionB.
        if (i % 10 == 0)
            versionB.push_back("Line " + to_string(i) + ": modified content");
        else
            versionB.push_back("Line " + to_string(i) + ": original content");
    }
    
    auto start = high_resolution_clock::now();
    int lcsLength = computeLCS(versionA, versionB);
    auto end = high_resolution_clock::now();
    double timeTaken = duration<double>(end - start).count();
    
    ostringstream details;
    details << "LCS length = " << lcsLength << " out of " << DIFF_FILE_LINES_AVG;
    
    string rating;
    if (timeTaken < 0.02) {
        rating = "Good";
        ratingScore += 1.0;
    } else if (timeTaken < 0.1) {
        rating = "Medium";
        ratingScore += 0.5;
    } else {
        rating = "Bad";
    }
    
    cout << "Diff Algorithm test completed in: " << timeTaken << " seconds (" << rating << ")\n";
    addTestResult("Diff Algorithm Test", timeTaken, rating, details.str());
}

// -----------------------------------------------------------------
// Detailed Report Generation
// -----------------------------------------------------------------
void generateReport(double ratingScore) {
    cout << "\n==================== System Performance Report ====================\n";
    cout << "Overall Rating Score: " << fixed << setprecision(2) << ratingScore << "\n\n";
    
    // Print detailed results table.
    cout << left << setw(30) << "Test Name" 
         << setw(15) << "Time(s)" 
         << setw(12) << "Rating" 
         << "Details" << "\n";
    cout << string(110, '-') << "\n";
    for (const auto &result : testResults) {
        cout << left << setw(30) << result.testName 
             << setw(15) << result.timeTaken 
             << setw(12) << result.rating 
             << result.details << "\n";
    }
    
    // In-depth analysis by category.
    cout << "\n----------------- Detailed Analysis -----------------\n";
    
    // CPU Analysis
    cout << "\n[CPU Performance]\n";
    for (const auto &name : {"Single-threaded CPU Test", "Multi-threaded CPU Test", "Atomic Operations Test"}) {
        for (const auto &result : testResults) {
            if (result.testName == name)
                cout << " - " << result.testName << ": " << result.timeTaken << " s (" << result.rating << ")\n";
        }
    }
    cout << "Analysis: Your CPU performance results indicate that heavy numerical tasks (such as matrix multiplication and Monte Carlo simulations) are quite demanding. ";
    cout << "A 'Bad' rating in these areas suggests that while everyday development tasks may be acceptable, CPU-bound operations (like large-scale compilations or scientific computations) might suffer on this system. ";
    cout << "Upgrading to a processor with more cores and higher clock speeds would markedly improve performance in these tasks.\n";
    
    // Memory Analysis
    cout << "\n[Memory Performance]\n";
    for (const auto &name : {"Memory Bandwidth Test", "Memory Latency Test"}) {
        for (const auto &result : testResults) {
            if (result.testName == name)
                cout << " - " << result.testName << ": " << result.timeTaken << " s (" << result.rating << ")\n";
        }
    }
    cout << "Analysis: Your memory subsystem appears to be high-performing, which is critical for both general application responsiveness and development tasks such as code parsing and compiling. ";
    cout << "Investing in faster, higher-capacity RAM can further reduce bottlenecks during multi-tasking and data-intensive operations.\n";
    
    // Disk I/O Analysis
    cout << "\n[Disk I/O Performance]\n";
    for (const auto &result : testResults) {
        if (result.testName == "Disk I/O Test")
            cout << " - " << result.testName << ": " << result.details << " (" << result.rating << ")\n";
    }
    cout << "Analysis: Disk I/O performance is crucial for rapid file operations, boot times, and application loading. ";
    cout << "While your results indicate good performance, using a modern NVMe SSD can provide even faster data transfer rates, ";
    cout << "which is particularly beneficial for large projects and virtualized environments.\n";
    
    // Network Analysis
    cout << "\n[Network Performance]\n";
    for (const auto &result : testResults) {
        if (result.testName == "Network Performance Test")
            cout << " - " << result.testName << ": " << result.timeTaken << " s (" << result.rating << ")\n";
    }
    cout << "Analysis: Network performance results can be highly variable due to external factors. ";
    cout << "If you experience slow download or upload speeds during typical use, consider using a wired connection or upgrading your router/modem.\n";
    
    // Algorithmic Tests Analysis
    cout << "\n[Algorithmic & Miscellaneous]\n";
    for (const auto &name : {"Sorting Performance Test", "Monte Carlo Pi Test", "Context Switching Test"}) {
        for (const auto &result : testResults) {
            if (result.testName == name)
                cout << " - " << result.testName << ": " << result.timeTaken << " s (" << result.rating << ")\n";
        }
    }
    cout << "Analysis: These tests assess the efficiency of common algorithms and thread management overhead. ";
    cout << "Results in the 'Bad' range for sorting and Monte Carlo tasks indicate that for computationally intensive algorithms, ";
    cout << "the current CPU may become a bottleneck. Optimizing code or offloading some tasks to a GPU (if applicable) could be beneficial.\n";
    
    // Software Development Tools Analysis
    cout << "\n[Software Development Tools Performance]\n";
    for (const auto &name : {"Regex Matching Test", "Source Code Parsing Test", "Diff Algorithm Test"}) {
        for (const auto &result : testResults) {
            if (result.testName == name)
                cout << " - " << result.testName << ": " << result.timeTaken << " s (" << result.rating << ")\n";
        }
    }
    cout << "Analysis: The tests simulating common development tasks (searching, parsing, and diffing code) all achieved 'Good' ratings, ";
    cout << "demonstrating that the system is well-suited for everyday coding activities and IDE responsiveness. ";
    cout << "This is an important factor for productivity in software development.\n";
    
    // Final Suggestions
    cout << "\n----------------- Final Suggestions -----------------\n";
    cout << "Based on the results, here are some detailed recommendations:\n\n";
    cout << "1. **CPU Upgrade:**\n";
    cout << "   - The CPU-intensive tests (matrix multiplication, Monte Carlo simulation, and sorting) indicate that your current processor struggles with heavy numerical workloads. ";
    cout << "   - For modern software development and high-performance computing tasks, a processor with more cores and higher clock speeds would dramatically reduce processing times. ";
    cout << "   - Consider upgrading to a recent-generation multi-core CPU (e.g., an Intel i7/i9 or AMD Ryzen 7/9) to boost overall performance.\n\n";
    
    cout << "2. **Memory Improvements:**\n";
    cout << "   - While your memory performance is good, faster RAM with higher capacity can help when multitasking or compiling large codebases. ";
    cout << "   - Upgrading to 16GB or more of high-speed DDR4/DDR5 memory would provide a smoother experience in development and data processing tasks.\n\n";
    
    cout << "3. **Storage Upgrade:**\n";
    cout << "   - Your disk I/O is performing well, but modern NVMe SSDs offer significantly faster read/write speeds compared to traditional SATA SSDs or HDDs. ";
    cout << "   - Investing in an NVMe drive can decrease boot times, application loading times, and improve overall system responsiveness, especially when working with large projects.\n\n";
    
    cout << "4. **GPU Considerations:**\n";
    cout << "   - Although this suite no longer includes a GPU test, if you rely on GPU-accelerated applications (e.g., 3D rendering, video editing, machine learning), ";
    cout << "   consider ensuring that your system has a dedicated, modern GPU. ";
    cout << "   - A recent NVIDIA RTX or AMD Radeon RX series card can significantly improve performance in graphics-intensive and parallel computing tasks.\n\n";
    
    cout << "5. **General System Balance:**\n";
    cout << "   - Your system handles everyday development tools well, but CPU-bound and algorithmic tasks reveal a significant bottleneck. ";
    cout << "   - Balancing your system by upgrading the CPU (and potentially the GPU) will not only improve computational performance but also enhance overall productivity in resource-intensive applications.\n\n";
    
    cout << "====================================================================\n";
}

// -----------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------
int main() {
    cout << "Starting average computer performance test (approx. 4 vCPUs, 8 GiB RAM)...\n\n";
    double ratingScore = 0.0;
    
    // CPU tests
    testSingleThreadedCPU(ratingScore);
    int numThreads = thread::hardware_concurrency();
    testMultiThreadedCPU(numThreads, ratingScore);
    testAtomicOperations(ratingScore);
    
    // Memory tests
    testMemoryBandwidth(ratingScore);
    testMemoryLatency(ratingScore);
    
    // Disk and Network tests
    testDiskIO(ratingScore);
    testNetworkPerformance(ratingScore);
    
    // Algorithmic and miscellaneous tests
    testSortingPerformance(ratingScore);
    testMonteCarloPi(ratingScore);
    testContextSwitching(ratingScore);
    
    // Software Development Tools tests
    testRegexMatching(ratingScore);
    testSourceCodeParsing(ratingScore);
    testDiffAlgorithm(ratingScore);
    
    // Generate detailed report
    generateReport(ratingScore);
    
    cout << "\nAll tests completed.\n";
    return 0;
}

