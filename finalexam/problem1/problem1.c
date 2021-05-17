#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#endif
#include "start_index.h"

#define N 108765

int main(int argc, char* argv[]) {
  printf("hi (serial)\n");
#ifdef _OPENMP
  int thread_count = 2;
#else
  int thread_count = 1;
#endif
  if (argc==2) {
    thread_count = atoi(argv[1]);
  } else {
    printf("using default %d threads\n",thread_count);
  }

  double sum=0;
  double a[N];
  for (int i=0; i<N; ++i) {
    a[i]=1;
  }

double sTime = omp_get_wtime();

#pragma omp parallel num_threads(thread_count)
{
    int rank = omp_get_thread_num();
    int num_threads = omp_get_num_threads();
    double local_sum=0;
    int mystart =start_index( N,num_threads,rank);
    int myend = start_index(N,num_threads,rank+1)-1;
    printf("mystart=%d, myend=%d\n",mystart, myend);
    for (int i=mystart; i<=myend; ++i) {
      local_sum+=a[i];
    }
    #pragma omp critical
    sum+=local_sum;
}

  double eTime = omp_get_wtime();
  printf("time taken = %.4f\n", (eTime-sTime));

  printf("bye (serial)\n");
  printf("sum=%f (N=%d)\n",sum,N);
  return 0;
}
