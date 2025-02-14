%option noyywrap

%{
    #include<stdio.h>
%}

%%  
[+][0-9]+ { printf("This is a positive number\n"); }
[0-9]+ { printf("This is a positive number\n"); }
-[0-9]+ { printf("This is a negative number\n"); }
.*   { printf("Wrong Input Enter a number\n"); }
%%  

int main() {
    printf("Enter input\n");
    yylex();
    return 0;
}
