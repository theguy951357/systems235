#include <stdio.h>

//functions must be declared before first use.
void print_array(int x[], int size){

	for(int i = 0; i<size; i++){
		printf("x[%d]=%d\n",i,x[i]);
	}

}

int double_it(int x){
	return 2*x;
}

void fun1(int z){
	z = 999;
}

int main(){

	//note that the square brackets are after the variable name
	int arr[5];//NOT INITIALIZED! data inside is garbage
	arr[0]=77;
	arr[4]=123;
	print_array(arr,5);
	//C doesnt have array bounds checking
	//print_array(arr,6000);//this will likely crash.
	printf("%d\n",double_it(7));
	int val = 123;
	fun1(val);
	printf("val=%d\n",val);
}
