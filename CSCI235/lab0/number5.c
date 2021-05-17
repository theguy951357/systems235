#include <stdio.h>

int above(int nums[],int size,int n){
	int count=0;
	for(int i=0; i<size; i++){
		if(nums[i] > n){
			count++;
		}
	}

	return count;
}

int main(){

	int arr[5];
	int arr2[5];
	for(int i = 0; i <5; ++i){
	  arr[i]=i;
	  arr2[i]=i+1;
	}
	printf("You have %d things higher than 1\n",above(arr,5,1));
	printf("You have %d things higher than 3\n",above(arr2,5,3));



}
