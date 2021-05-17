#include <stdio.h>

int main(){

printf("Enter characters, one at a time,\nuse ctrl-d to quit:\n");

int x,count;
x = getchar();
	while(x != EOF){
		if(x == 'X'){
			count++;
		}
		x = getchar();
	}
printf("You entered X %d times\n", count);


}
