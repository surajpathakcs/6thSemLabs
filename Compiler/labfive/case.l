%option noyywrap

%{
    #include<stdio.h>
%}

%%
^[A-Z]* {printf("UPPERCASE STRINGS");}
^[a-z]* {printf("lowercase string");}
^[a-zA-Z]* {printf("both mixed");}




.*   { printf("Invalid input\n");}

%%

int main() {
    printf("Enter input\n");
    yylex();
    return 0;
};

