//Write a C Program to to test  whether the given input is keyword or not.

#include<stdio.h>
#include<string.h>

int main() {
    char keyword[32][15] = {"auto", "break", "case", "char",
    		"const", "continue", "default", "do",
    		"double", "else", "enum", "extern",
  		    "float", "for", "goto", "if",
    		"int", "long", "register", "return",
    		"short", "signed", "sizeof", "static",
    		"struct", "switch", "typedef", "union",
    		"unsigned", "void", "volatile", "while"};
    int i = 0, checker = 0;
    char choice[15];

    printf("Enter the keyword that you want to test to test: \n");
    gets(choice);
    printf("Input : %s" ,choice);
    

   while(i<32){
    if(strcmp(keyword[i],choice) == 0){
    	checker=1;
    	break;
	}
	i++;
	}

    if(checker==0){    	
    	printf("\nGiven input is an invalid keyword\n");
		return 0;
	}
	printf("\nGiven input is a valid keyword\n");
    return 0;
}
