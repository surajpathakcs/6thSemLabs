//Write a C program to identify whether given line is comment or not

#include<stdio.h>
#include<string.h>

int main() {
    char input[100];
    int redo , length;

    do {
    	redo=0;
        printf("Enter the string: \n");
       // scanf("%s", input);
       fgets(input,sizeof(input),stdin);
	   length = strlen(input);
	   
	   //Remove excess white space at the end
	   while (length > 0 && isspace(input[length - 1])) {
            length--;
            input[length] = '\0';
		}
		//check comment
		if (input[0] == '/' && input[1] == '/') {
            printf("This is a single-line comment.\n");
        } else if (input[0] == '/' && input[1] == '*' && input[length - 2] == '*' && input[length - 1] == '/') {
            printf("This is a multi-line comment.\n");
        }else {
            printf("This is not a comment.\n");
        }
        printf("\n 1 to Redo \n anyother key to exit : \n");
        scanf("%d", &redo);
        getchar();
    } while (redo == 1);

    return 0;
}

