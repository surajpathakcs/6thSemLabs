//Write a c program to implement the design of lexical analyser to recognize token (identifier , Keyword , Number , Operator and Special character etc).

#include<stdio.h>

int main(){
	   
    FILE *file;
    char input[1000];
    
    file = fopen("file.txt", "a");
    fclose(file);

    // Open the file in append mode
    file = fopen("file.txt", "w");
    printf("Enter text to append to the file (press Ctrl+D to stop input):\n");
    // Read input from the console until EOF (Ctrl+D or Ctrl+Z)
    while (fgets(input, sizeof(input), stdin) != NULL) {
        fputs(input, file);  // Append the input text to the file
    }
    // Close the file
    fclose(file);

    printf("Text successfully appended to the file.\n");
    
    file = fopen("file.txt","r");

            


   fclose(file);  // Close the file when done
    return 0;
}
	  
	
