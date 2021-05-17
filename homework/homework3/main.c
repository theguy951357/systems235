#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "read_data.h"
#include "write_pgm.h"

int main(int argc, char* argv[]){


  if(argv[1]==NULL||argv[2]==NULL){
    fprintf(stderr, "not enough arguments\n");
    exit(1);
  }
  Matrix matrix = import_data(argv[1]);
  write_pgm(matrix, argv[2]);

  return 0;
}
