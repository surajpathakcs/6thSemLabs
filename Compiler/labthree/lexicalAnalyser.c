#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

const char *keywords[] = {
    "for", "do", "char", "int", "float", "if", "else", "while", "return",
        "switch", "case", "break", "continue", "goto", "typedef", "struct",
        "union", "enum", "long", "short", "double", "const", "volatile",
        "signed", "unsigned", "sizeof", "inline", "restrict", "auto",
        "extern", "register", "static"
};

const char *operators[] = {
    "+", "-", "*", "/", "%", "++", "--", "=", "+=", "-=", "*=", "/=", "%=",
    "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!", "&", "|", "^", "<<", ">>"
};

// Function to classify tokens as keywords, identifiers, numbers, or operators
void classifyToken(char *str, FILE *f_kw, FILE *f_id) {
    int isKeyword = 0;
	int i;
    // Check if it's a keyword
    for (i = 0; i < 32; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            isKeyword = 1;
            break;
        }
    }

    // Classify token
    if (isKeyword) {
        fprintf(f_kw, "%s\n", str);
    } else {
        fprintf(f_id, "%s\n", str);
    }
}

// Check if a given string is an operator
int isOperator(char *str) {
	int i;
    for (i = 0; i < 27; i++) {
        if (strcmp(str, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *f1, *f_id, *f_kw, *f_sc, *f_op, *f_num;
    char c, str[MAX_LEN];
    int i = 0, lineno = 1;

    // Open files for input and output
    printf("Enter the C program:\n");
    f1 = fopen("input", "w");
    if (f1 == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    // Take program input
    while ((c = getchar()) != EOF) {
        putc(c, f1);
    }
    fclose(f1);

    // Re-open input file for reading
    f1 = fopen("input", "r");
    f_id = fopen("identifier", "w");
    f_kw = fopen("keyword", "w");
    f_sc = fopen("specialchar", "w");
    f_op = fopen("operators", "w");
    f_num = fopen("numbers", "w");

    if (f1 == NULL || f_id == NULL || f_kw == NULL || f_sc == NULL || f_op == NULL || f_num == NULL) {
        printf("Error opening output files.\n");
        return 1;
    }

    // Process input characters
    while ((c = fgetc(f1)) != EOF) {
        if (isdigit(c)) { // Handling numbers
            str[i++] = c;
            while (isdigit(c = fgetc(f1))) { // Capture entire number
                str[i++] = c;
            }
            str[i] = '\0';
            fprintf(f_num, "%s\n", str);  // Print number in the 'numbers' file
            i = 0;
            ungetc(c, f1); // Put the non-digit character back to continue parsing
        } else if (isalpha(c)) { // Handling keywords and identifiers
            str[i++] = c;
            c = fgetc(f1);
            while (isalnum(c) || c == '_') { // Capture identifier or keyword
                str[i++] = c;
                c = fgetc(f1);
            }
            str[i] = '\0';
            classifyToken(str, f_kw, f_id);
            i = 0;
            ungetc(c, f1);
        } else if (!isspace(c)) { // Handling operators and special characters
            str[i++] = c;
            c = fgetc(f1);
            if (!isspace(c)) {
                str[i++] = c;
            } else {
                ungetc(c, f1);
            }
            str[i] = '\0';

            if (isOperator(str)) {
                fprintf(f_op, "%s\n", str);
            } else {
                fprintf(f_sc, "%s\n", str);
            }
            i = 0;
        }
    }

    // Close input and output files
    fclose(f1);
    fclose(f_id);
    fclose(f_kw);
    fclose(f_sc);
    fclose(f_op);
    fclose(f_num);

    // Output results
    printf("\nKeywords are:\n");
    f_kw = fopen("keyword", "r");
    while (fscanf(f_kw, "%s", str) != EOF) {
        printf(" %s", str);
    }
    fclose(f_kw);

    printf("\nIdentifiers are:\n");
    f_id = fopen("identifier", "r");
    while (fscanf(f_id, "%s", str) != EOF) {
        printf(" %s", str);
    }
    fclose(f_id);

    printf("\nSpecial characters are:\n");
    f_sc = fopen("specialchar", "r");
    while ((c = getc(f_sc)) != EOF) {
        printf(" %c", c);
    }
    fclose(f_sc);

    printf("\nOperators are:\n");
    f_op = fopen("operators", "r");
    while (fscanf(f_op, "%s", str) != EOF) {
        printf(" %s", str);
    }
    fclose(f_op);

    printf("\nNumbers are:\n");
    f_num = fopen("numbers", "r");
    while (fscanf(f_num, "%s", str) != EOF) {
        printf(" %s", str);
    }
    fclose(f_num);

    return 0;
}

