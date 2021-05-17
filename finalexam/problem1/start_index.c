#include<stdio.h>
#include "start_index.h"
#include <math.h>

int start_index(int N, int num_threads, int rank){

	//int index;
	//if the rank equals the number of threads, return N
	if(rank == num_threads){
		return N;
	//if the rank is 0, there is no need to calculate anything. return 0
	}else if(rank == 0){
		return 0;
	}else{
		//getting the remainder
		int extra = N % num_threads;
		printf("extra=%d\n",extra);
		//getting where the index would be.
		int index = N/num_threads*rank;
		printf("index=%d\n",index);

		//adjust for remainder. if it is less than the remainder, add rank
		//if it is more than the remainder, add the ramainder
		if(rank < extra){
			index+= rank;
		}else{
			index += extra;
		}
		return index;
	}

}
