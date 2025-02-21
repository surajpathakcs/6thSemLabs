%option noyywrap

%{
    #include<stdio.h>
%}

%%
"+"|"-"|"*"|"/"|"%"|"++"|"--"|"&&"|"||"|"!"|"=="|">="|"<="|"!="|"<"|">"|"="|"^"|"<<"|">>"|"~"|"+="|"-="|"*="|"/="|"%="|"<<="|">>="  {printf("Valid Operator\n");}


.*   { printf("Not a valid Operator\n");}

%%

int main() {
    printf("Enter the input\n");
    yylex();
    return 0;
};
