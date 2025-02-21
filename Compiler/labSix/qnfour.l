%{
#include <stdio.h>
#include <stdlib.h>  // Include stdlib.h for atoi()
#include "qnfour.tab.h"
%}

%%
[0-9]+     { yylval = atoi(yytext); return NUMBER; }
[\n]       { return 0; }   // Stop parsing on newline
.          { return yytext[0]; } // Return single characters as tokens
%%

int yywrap() {
    return 1;
}
