#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix create_matrix(unsigned rows, unsigned columns){
//  printf("beginning create_matrix\n");
  Matrix matrix;
  matrix.rows = rows;
  matrix.columns = columns;
  matrix.data = (double**)malloc(rows*sizeof(double*));
  for(int i = 0;i<rows; i++){
    matrix.data[i]=(double*)calloc(columns,sizeof(double));
    for(int j = 0; j<columns; j++){
      matrix.data[i][j]=0.0;
    }
  }
//  printf("matrix created\n\n");
  return matrix;
}

void print_matrix(Matrix matrix){
  printf("printing matrix\n");

  for(int i=0; i < matrix.rows; i++){
   // printf("[ ");
    for(int j=0; j < matrix.columns; j++){
      printf("%f ", matrix.data[i][j]);
   //   if(j!=(matrix.columns-1)){
   //     printf(", ");
   //   }
    }
    printf("\n");

  }

  printf("matrix printed\n\n");
}

void free_matrix(Matrix matrix){
  printf("freeing matrix...");
  for(int i=0; i < matrix.rows; i++){

    free(matrix.data[i]);
  }
  free(matrix.data);
  printf("matrix has been freed\n\n");
}

//int main(){

//  Matrix matrix = create_matrix(8,7);
//  print_matrix(matrix);
//  free_matrix(matrix);
//  printf("end of program.\n");
//  return 0;
//}
