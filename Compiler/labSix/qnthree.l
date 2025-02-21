%option noyywrap
%{
   #include<stdio.h>
   #include"qnthree.tab.h"
%}
%%
[0-9] { yylval = atoi(yytext); return DIGIT; }
[a-zA-Z]+ {return LETTER;}
[\n|.] {return 0;}

%%