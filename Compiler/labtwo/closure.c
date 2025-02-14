#include <stdio.h>
#include <string.h>

int main() {
    char str[20];
    int choice;

    do {
        int i = 0, state = 0; // Reset state and iterator for each string
        printf("Enter the string: ");
        scanf("%s", str);

        while (str[i] != '\0') {
            switch (state) {
                case 0: // Initial state (a^*)
                    if (str[i] == 'a') {
                        state = 0; // Stay in a^*
                    } else if (str[i] == 'b') {
                        state = 1; // Transition to b^+ or abb
                    } else {
                        state = 4; // Invalid character
                    }
                    break;

                case 1: // After one 'b' (possible a^*b or abb)
                    if (str[i] == 'b') {
                        state = 2; // Transition to abb or b^+
                    } else if (str[i] == 'a') {
                        state = 4; // Invalid transition
                    } else {
                        state = 4; // Invalid character
                    }
                    break;

                case 2: // After two 'b's (abb or b^+)
                    if (str[i] == 'b') {
                        state = 2; // Stay in b^+
                    } else if (str[i] == 'a') {
                        state = 4; // Invalid transition
                    } else {
                        state = 4; // Invalid character
                    }
                    break;

                default: // Invalid state
                    state = 4; // Invalid string
            } 3
            i++;
        }

        // Accept states: 0 (a^*), 2 (abb), or 1 (a^*b^+ with one 'b')
        if (state == 0 || state == 1 || state == 2) {
            printf("String is accepted\n");
        } else {
            printf("String is rejected\n");
        }

        // Ask the user if they want to check another string
        printf("Do you want to check another string? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    printf("Program terminated.\n");
    return 0;
}
