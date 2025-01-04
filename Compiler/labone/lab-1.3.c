//write a C program to test whether given identifier is valid or not.
#include<stdio.h>
#include<string.h>
#include <ctype.h>

int main(){
	int pass=1;
	int i;
    char choice[25];


	 char keyword[32][15] = {"auto", "break", "case", "char",
    		"const", "continue", "default", "do",
    		"double", "else", "enum", "extern",
  		    "float", "for", "goto", "if",
    		"int", "long", "register", "return",
    		"short", "signed", "sizeof", "static",
    		"struct", "switch", "typedef", "union",
    		"unsigned", "void", "volatile", "while"};
    

    printf("Enter the Identifier \n");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0'; //Remove new line character
    printf("Input : %s" ,choice);
    

   for (i = 0; i < 32; i++) {
    if(strcmp(keyword[i],choice) == 0){
    	printf("\nGiven choice is a keyword and not a valid identifier\n");
    	return 0;
	}
	}

    if (!isalpha(choice[0]) && choice[0] != '_') {
        printf("\nInvalid Identifier: The first character must be a letter or underscore.\n");
        return 0;
    }

   for( i = 1 ; i < strlen(choice); i++){

    if( !isalnum(choice[i]) || isspace(choice[i])){
    	if( choice[i]!='_'){
        	printf(" \n Invalid Identifier");
    		pass= 0;
			break;
		
		}
       }
   }
	if(pass)
 		printf(" \n Valid Identifier");

return 0;
}
