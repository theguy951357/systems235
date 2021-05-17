#include <stdio.h>
#define VAR 77// will substitute VAR with 77.

//this is a comment
/*
	this is a block comment.
*/
int main(){
	printf("hello, world\n");
	int x = VAR;
	int y = 4;
	printf("x=%d\ny=%d\n",x,y);//%d is for ints, %f is for floats.
	while(x>0){
		printf("x is %d\n",x);
		x--;
	}
}
