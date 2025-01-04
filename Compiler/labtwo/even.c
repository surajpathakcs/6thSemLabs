#include<stdio.h>

int main(){
	int state = 0, i = 0;
	char s[100],c;
	
	printf("Enter the input string ");
	scanf("%s",s);
	
	
    while (s[i] != '\0') {
        c = s[i++];
		
		switch(state){
			case 0:
				if( c== '0')
					state = 2;
				else if( c == '1')
					state = 1;
				else{
					state = -1;
				}
				break;
			case 1: 
				 if (c == '0')
                    state = 3;
                else if (c == '1')
                    state = 0;
                else {
                    state = -1; 
                }
                break;
             case 2:
                if (c == '0')
                    state = 0;
                else if (c == '1')
                    state = 3;
                else {
                    state = -1; 
                }
                break;
             case 3:
                if (c == '0')
                    state = 1;
                else if (c == '1')
                    state = 2;
                else {
                    state = -1; 
                }
                break;
		}
		
		}
	
		if(state == 0 || state == 3){
			printf("string is accepted ");
		}
		else{
			printf("String is not accepted");
		}
	return 0;
}
