
%{
    #include <stdio.h>
    #include <conio.h>  
    int yylex();  
    void yyerror(const char *s); 
%}

%token A B

%%

S : A S B
  | /* empty */ ;

%%

int main() {
    printf("Enter the input:\n");
    if (yyparse() == 0)
        printf("Valid\n");
    getch();
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid\n");
}
