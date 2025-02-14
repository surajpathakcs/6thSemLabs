#include <stdio.h>
#include <string.h>
//swap with even.c

int main() {
    char str[20];
    int choice;

    do {
        int i = 0, state = 0; // Reset variables for each string
        printf("Enter the string: ");
        scanf("%s", str);

        while (str[i] != '\0') {
            switch (state) {
                case 0: // Even 0's and even 1's
                    if (str[i] == '0') {
                        state = 1;
                    } else if (str[i] == '1') {
                        state = 2;
                    } else {
                        state = 4; // Invalid character
                    }
                    break;

                case 1: // Odd 0's and even 1's
                    if (str[i] == '0') {
                        state = 0;
                    } else if (str[i] == '1') {
                        state = 3;
                    } else {
                        state = 4; // Invalid character
                    }
                    break;

                case 2: // Even 0's and odd 1's
                    if (str[i] == '0') {
                        state = 3;
                    } else if (str[i] == '1') {
                        state = 0;
                    } else {
                        state = 4; // Invalid character
                    }
                    break;

                case 3: // Odd 0's and odd 1's
                    if (str[i] == '0') {
                        state = 2;
                    } else if (str[i] == '1') {
                        state = 1;
                    } else {
                        state = 4; // Invalid character
                    }
                    break;

                default:
                    printf("Invalid string\n");
                    state = 4; // Move to invalid state
            }
            i++;
        }

        if (state == 0) {
            printf("String is accepted\n");
        } else {
            printf("String is rejected\n");
        }

        printf("Do you want to check another string? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    printf("Program terminated.\n");
    return 0;
}
