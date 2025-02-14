%option noyywrap

%{
    #include<stdio.h>
%}

%%  
[9][6-8][0-9]{8} { printf("This is a number\n"); }

.*   { printf("It is not a number\n"); }
%%  

int main() {
    printf("Enter input\n");
    yylex();
    return 0;
}
