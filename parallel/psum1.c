//warning this code has a bug
#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#endif

#define N 1000000

int main(int argc, char*argv[]){
	printf("hi(serial)\n");
#ifdef _OPENMP
	int thread_count = 2;
#else
	int thread_count = 1;
#endif
	if(argc == 2){
		thread_count = atoi(argv[1]);
	}else{
		printf("using default %d threads\n", thread_count);
	}

	double sum = 0;
	double a[N];
	for (int i = 0; i<N; ++i){
		a[i] = 1;
	}

double sTime = omp_get_wtime();
#pragma omp parallel num_threads(thread_count)
{
	int rank = omp_get_thread_num();
	int threads = omp_get_num_threads();
	//printf("parallel here (thread%d)!\n", rank);
	for(int i = rank; i<N; i+= threads){
		//ACCESSING A SHARED VARIABLE WITHOUT PROTECTING = BUG HERE!
		sum += a[i];
	}
}
	double eTime = omp_get_wtime();
	printf("time taken = %.4f\n", (eTime - sTime));

	printf("bye(serial)\n");
	printf("sum=%f (N=%d)\n", sum,N);
	return 0;

}
