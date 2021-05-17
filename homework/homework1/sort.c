#include <stdio.h>


void print_array(int arr[], int size){

  for(int i = 0; i < size; i++){

    if(i==size-1){

      printf("%d\n",arr[i]);

    }else{

      printf("%d, ",arr[i]);

    }
  }
}


void selection_sort(int ar[], int size){

	int min = 0;
	printf("unsorted array: ");
	print_array(ar,size);
	for(int i = 0; i<size; i++){

	  for(int j = i; j<size; j++){

	    if(ar[j]<ar[i]){

		min = ar[j];
		ar[j] = ar[i];
		ar[i] = min;
	    }
	  }
	}

	printf("sorted array: ");
	print_array(ar,size);
	printf("\n");
}



int main(){

  int ar1[]={1,6,5,8};
  int ar2[]={99,-2,65,0,88,1234,5,8,2,2,3,4};
  int ar3[] = {-50,5,4,5,'y',5,2,2,3,7,999,0,80,-1,-5};
  int ar4[] = {'t','e','W','a','a',':'};

  selection_sort(ar1,4);
  selection_sort(ar2,12);
  selection_sort(ar3,15);
  selection_sort(ar4,6);


}
