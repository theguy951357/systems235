#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#endif

int main(int argc, char* argv[]){
	printf("hi (serial)\n");
#pragma omp parallel
{
	printf("hello from thread %d!\n", omp_get_thread_num());
}

}
