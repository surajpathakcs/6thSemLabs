%option noyywrap

%{
    #include<stdio.h>
%}

%%
[0-9]+ {printf("Input is a number");}
-[0-9]+ {printf("Input is a number");}

	
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {printf("valid keyword\n");}


[a-zA-Z_]+[a-zA-Z0-9_]+ {printf("Valid Identifier\n");}

.*   { printf("Not a valid keyword or identifier or number\n");}

%%

int main() {
    printf("Enter the input\n");
    yylex();
    return 0;
};



