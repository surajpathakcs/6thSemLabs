%{
    #include <stdio.h>
    int yylex(void);             
    void yyerror(const char *s); 
%}

%token LETTER DIGIT


%%
var: LETTER 
    | LETTER rest
rest: LETTER rest
     | DIGIT rest
     | LETTER
      | DIGIT;

%%

int main() {
    printf("Enter the input:\n");
    if (yyparse() == 0)
        printf("Valid\n");
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid\n");
}
