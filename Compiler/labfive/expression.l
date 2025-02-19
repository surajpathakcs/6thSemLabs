%option noyywrap
%{
#include <stdio.h>

int paramsCount = 0, operatorCount = 0, operandCount = 0;
%}

%%

[a-zA-Z_][a-zA-Z0-9_]*     { operandCount++; }  /* Variables */
[0-9]+                     { operandCount++; }  /* Numbers */
[\+\-\*\/\%\=]             { operatorCount++; } /* Operators */
"("                        { paramsCount++; }
")"                        { paramsCount--; }
[ \t]*                     {/* Ignore spaces and tabs */}

\n                         { return 1; } /* End of input */

%%

int main() {
	printf("\nEnter an arithmetic expression: \n");
	while (1) {  // Loop to take multiple inputs
        
        
        paramsCount = operatorCount = operandCount = 0;  // Reset counts for each input
        yylex(); // Process input

        if (paramsCount == 0 && operatorCount > 0 && (operandCount == operatorCount + 1))
            printf("Valid arithmetic expression.\n");
        else
            printf("Invalid arithmetic expression.\n");
	getchar();
        getchar(); // To consume the newline character

        
    }

    return 0;
}