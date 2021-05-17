#include <stdio.h>

int main(){

	printf("hello\n");
	char c = getchar();
	char c2 = getchar();
	printf("c = %c\n", c);
	printf("c2 = %c\n", c2);
	// single quotes denotes a char type
	// double quotes is a "c-style string"
	if(c2 == '\n'){
		printf("c2 is a new line\n");
	}
	printf("Enter characters, enter ctrl-d to quit.\n");
	int mychar;
	mychar = getchar();
	while(mychar != EOF){
		printf("%c\n",mychar);
		mychar = getchar();
	}
}
