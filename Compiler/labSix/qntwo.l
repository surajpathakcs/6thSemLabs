%{
#include <stdio.h>
#include <stdlib.h>  // Include stdlib.h for atoi()
#include "q2yyc.tab.h"
%}

%%
[0-9]+     { yylval = atoi(yytext); return NUMBER; }
[a-zA-Z]+  { return ID; }  // Ensure ID is defined in YACC
[\n]       { return 0; }   // Stop parsing on newline
.          { return yytext[0]; } // Return single characters as tokens
%%

int yywrap() {
    return 1;
}
