//Write a program to simulate lexical analyser for validating operators.
#include <stdio.h>
#include <string.h>

int main() {
    char input[10];
    int choice;
    do {
        printf("Enter an operator: ");
        scanf("%s", input);

        if (!(strcmp(input, "+")) || !(strcmp(input, "-")) || !(strcmp(input, "*")) ||
            !(strcmp(input, "/")) || !(strcmp(input, "%"))) {
            printf("%s is a valid arithmetic operator.\n", input);
        }
        else if (!(strcmp(input, "==")) || !(strcmp(input, "!=")) || !(strcmp(input, "<=")) ||
                 !(strcmp(input, ">=")) || !(strcmp(input, "<")) || !(strcmp(input, ">"))) {
            printf("%s is a valid relational operator.\n", input);
        }
        else if (!(strcmp(input, "&&")) || !(strcmp(input, "||")) || !(strcmp(input, "!"))) {
            printf("%s is a valid logical operator.\n", input);
        }
        else if (!(strcmp(input, "="))) {
            printf("%s is a valid assignment operator.\n", input);
        }
        else if (!(strcmp(input, "&")) || !(strcmp(input, "|")) || !(strcmp(input, "^")) ||
                 !(strcmp(input, "~")) || !(strcmp(input, "<<")) || !(strcmp(input, ">>"))) {
            printf("%s is a valid bitwise operator.\n", input);
        }
        else {
            printf("%s is not a valid operator.\n", input);
        }

        printf("Do you want to check again? (y--->1/n---->0): ");
        scanf(" %d", &choice);
    } while (choice == 1);

    return 0;
}
