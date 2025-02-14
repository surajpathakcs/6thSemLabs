%option noyywrap

%{
    #include<stdio.h>
%}

%%  
"hi" { printf("Hello\n"); }
.*   { printf("Wrong Input\n"); }
%%  

int main() {
    printf("Enter input\n");
    yylex();
    return 0;
}
