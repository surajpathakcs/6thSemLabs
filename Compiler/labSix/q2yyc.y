
%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token NUMBER ID
%left '+' '-'
%left '*' '/'
%right UMINUS  

%%

// Grammar rules
stmt_list: stmt stmt_list  // Allow multiple statements
         | /* empty */     // Allow pressing ENTER without exiting
         ;

stmt: expr { printf("Valid arithmetic expression\n"); }
    | ID { printf("Valid identifier\n"); }
    ;

expr:
      expr '+' expr  
    | expr '-' expr  
    | expr '*' expr  
    | expr '/' expr  
    | '-' expr %prec UMINUS  
    | '(' expr ')'  
    | NUMBER  
    | ID  
    ;

%%

void yyerror(const char *s) {
    printf("Invalid Input String\n");
}

int main() {
    printf("Enter arithmetic expressions :\n");
    while (1) {  // Keep taking input until user exits
        yyparse();
    }
    return 0;
}
