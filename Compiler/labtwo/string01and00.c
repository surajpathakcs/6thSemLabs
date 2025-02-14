#include<stdio.h>
//write a program to implement DFA that accepts string that ends with 00 and 01 where alphabets = {0,1}

int main(){
	int state=0,i=0,choice=1;
	char s[100],c; // Input string

	
	do{
	i=0;
	
	printf("Enter the input string (only 0s and 1s): ");
    scanf("%s", s); // Read the input string
    
    
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
					state = 4;
				break;
				
			case 1:
				if(c=='1')
					state=2;
				else if(c=='0')
					state = 3;
				else 
					state = 4;
				break;
			
			case 2:
				if(c=='1')
					state = 0;
				else if(c=='0')
					state = 1;
				else
					state = 4;
				break;
			case 3:
				if(c=='1')
					state = 2;
				else if(c=='0')
					state = 3;
				else
					state = 4;
				break;
			case 4:
				break;
		}
		
		
	}
	
	if(state==2){
		printf("\nGiven string is accepted as it ends with 01");
	}
	else if(state==3){
		printf("\nGiven string is accepted as it ends with 00");
	}else{
		printf("\nGiven String is not accepted by DFA");
	}
	
	
	
	printf("\nDo you want to test again?\nYes -> 1\nNo->0\n");
	scanf("%d",&choice);		
	}while(choice==1);
	
	return 0;
}
