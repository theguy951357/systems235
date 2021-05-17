#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_int_array(int* a, unsigned size, char* name) {
    for (unsigned i=0; i<size; i++) {
        printf("%s[%d]=%d\n",name,i,a[i]);
    }
}

int main(int argn, char *argv[]) {
    
    // pretend initial_size came from user input (ie. not known ahead of time)
    int initial_size = atoi(argv[1]);

    int *array = (int *) malloc(initial_size*sizeof(int));
    if(array == NULL){
      exit(0);
    }
    for (int i=0; i<initial_size; i++) {
        array[i]=i;
    }
    
    printf("original:\n");
    print_int_array(array,initial_size,"array");
    
    // pretend new_size came from user input, assume new_size>initial_size
    int new_size = atoi(argv[2]);
    
    // POINT A
     array = (int *) realloc(array,new_size*sizeof(int));
    if(array == NULL){
      exit(0);
    }

   // for (int i=0; i<initial_size; i++) {
   //     bigger[i]=array[i];
   // }
    
   // int *tmp = array;
   // array = bigger;
   // bigger = tmp;
    //free(bigger);
    // POINT B
    
    for (int i=initial_size; i<new_size; i++) {
        array[i]=2*i;
    }

    printf("resized:\n");
    print_int_array(array,new_size,"array");
    free(array);
}
