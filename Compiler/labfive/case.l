%option noyywrap

%{
    #include<stdio.h>
%}

%%
^[A-Z]* {printf("UPPERCASE STRINGS\n");}
^[a-z]* {printf("lowercase string\n");}
^[a-zA-Z]* {printf("both mixed\n");}




.*   { printf("Invalid input\n");}

%%

int main() {
    printf("Enter the input\n");
    yylex();
    return 0;
};

