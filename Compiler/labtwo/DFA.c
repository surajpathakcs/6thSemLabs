#include<stdio.h>

int main(){
	int state=0,i=0;
	char s[100],c; // Input string

    printf("Enter the input string (only 0s and 1s): ");
    scanf("%s", s); // Read the input strin
	
	
	
	while(s[i]!='\0'){
		printf("%c",s[i]);
		c=s[i++];
		
		switch(state){
			case 0:
				if(c=='0')
					state = 1;
				else if(c=='1')
					state = 0;
				else
					state = 3;
				break;
				
			case 1:
				if(c=='1')
					state=2;
				else if(c=='0')
					state = 1;
				else 
					state = 3;
				break;
			
			case 2:
				if(c=='1')
					state = 0;
				else if(c=='0')
					state = 1;
				else
					state = 3;
				break;
		}
		
	}
	
	if(state==2)
			printf("Given string is accepted");
		else
			printf("Given String is not accepted by DFA");
	
	
	return 0;
}
