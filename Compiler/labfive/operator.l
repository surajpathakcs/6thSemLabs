%option noyywrap

%{
    #include<stdio.h>
%}

%%
"+"|"-"|"*"|"/"|"%"|"++"|"--"|"&&"|"||"|"!"|"=="|">="|"<="|"!="|"<"|">"|"="|"^"|"<<"|">>"|"~"|"+="|"-="|"*="|"/="|"%="|"<<="|">>="  {printf("Valid Operator");}


.*   { printf("Not a valid Operator\n");}

%%

int main() {
    printf("Enter input\n");
    yylex();
    return 0;
};
