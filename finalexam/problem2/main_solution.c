#include <stdio.h>
#include <stdlib.h>

#define MEMORY_CAPACITY_WORDS 64
int memory[MEMORY_CAPACITY_WORDS];//the memory we can allocate
int* end;//a pointer to the last element of memory

int mymalloc_calls=0;

void mymalloc_init() {
    //initialize memory and end here
    memory[0]=MEMORY_CAPACITY_WORDS*sizeof(int);
    end = &memory[MEMORY_CAPACITY_WORDS-1];
}

void print_memory() {
    //uncomment this to print contents of memory
    for (int i=0; i<MEMORY_CAPACITY_WORDS; i++) {
        printf("memory[%d]=%d\n",i,memory[i]);
    }
}

void *mymalloc(int bytes_requested) {
    mymalloc_calls++;
    printf("mymalloc_call %d, bytes=%d\n",mymalloc_calls,bytes_requested);

    int bytes=bytes_requested+4;//room for header
    // bytes must be a multiple of 4
    if (bytes%4!=0) {
        bytes += (4-bytes%4);
    }
    //printf("bytes=%d\n",bytes);

    int * p = memory;
    while (p<end && (*p % 2==1 || *p<bytes)) {
        p+=(*p & -2)/sizeof(int);
    }
    if (p>=end) {
        printf("no free blocks found\n");
        return(0);
    } else {
        //printf("found a block\n");
    }
    int old_value = *p;//old block size
    *p = bytes+1;//+1 because allocated bit to be set
    if (old_value>bytes) {
        *(p+bytes/sizeof(int)) = old_value-bytes;
    }
    return p+1;
    //return malloc(bytes_requested);
}

void myfree(int* p) {

    (*(p-1))--;
    int current = (*(p-1));
//    printf("%d\n", *(p-1));
    //get a pointer to the next block
    int* next = (p-1)+(current/sizeof(int));
//    printf("%d\n", *next);
    // if the next block is divisible by 2 (free block) add that to the current block and move the pointer
    if(*next%2 == 0){
	(*(p-1))+= *next;
	*next = 0;
	next = (p-1);
    }
    //free(p);
}

void fill(int* a, int size, int val) {
    for (int i=0; i<size; i++) {
        *(a+i)=val;
    }
}

int main() {
    mymalloc_init();
    print_memory();

    //make some random malloc calls
    int max=10;
    int *data[max];
    int N=3;//how many pointers are being used
    for (int i=0; i<N; i++) {
        int size = rand()%10+1;//random number between 1 and 10
        data[i] = (int*)mymalloc(size*sizeof(int));
        fill(data[i], size, mymalloc_calls);
	print_memory();
    }

    //now make some random calls to malloc and free

    for (int i=0; i<10; i++) {
        //choose to malloc or free something with 50/50 probability each
        if (N<max && (double)rand()/RAND_MAX<.5) {
            int size = rand()%10+1;
            data[N] = (int*)mymalloc(size*sizeof(int));
            fill(data[N], size, mymalloc_calls);
            N++;
	print_memory();

        }
        if (N>0 && (double)rand()/RAND_MAX<.5) {
            //choose a random pointer to free
            int index = rand()%N;
            printf("freeing index %d\n",index);
            myfree(data[index]);
            //swap last element in data, so first N are the valid pointers
            data[index]=data[N-1];
            N--;
	print_memory();

        }
    }

}
