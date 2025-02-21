%option noyywrap

%{
   #include<stdio.h>
   #include "q1yyc.tab.h"
%}

%%
[a] {return A;}
[b] {return B;}
[\n] {return 0;}
. {return yytext[0];}
%%

