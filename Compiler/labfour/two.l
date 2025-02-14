%option noyywrap

%{
    #include<stdio.h>
%}

%%  
[0-9]*[02468] { printf("Even Number\n"); }
[0-9]*[13579] { printf("Odd Number\n"); }
.*   { printf("Wrong Input\n"); }
%%  

int main() {
    printf("Enter input\n");
    yylex();
    return 0;
}
