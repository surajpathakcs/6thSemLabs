%option noyywrap

%{
    #include<stdio.h>
%}

%%  
[a-zA-Z0-9._]+@"gmail.com" { printf("This is an email\n"); }

.*   { printf("It is not an email\n"); }
%%  

int main() {
    printf("Enter input\n");
    yylex();
    return 0;
}
