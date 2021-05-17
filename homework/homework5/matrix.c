#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix create_matrix(unsigned rows, unsigned columns){
//  printf("beginning create_matrix\n");
  Matrix matrix;
  matrix.rows = rows;
  matrix.columns = columns;
  matrix.data = (double**)malloc(rows*sizeof(double*));
  int i, j;
  for(i = 0; i+1<rows; i+=2){
    matrix.data[i]=(double*)calloc(columns,sizeof(double));
    matrix.data[i+1]=(double*)calloc(columns,sizeof(double));

  }
  for(;i<rows; i++){
    matrix.data[i]=(double*)calloc(columns,sizeof(double));
//    for( j = 0; j+1<columns; j+=2){
//      matrix.data[i][j]=0.0;
//      matrix.data[i][j+1] = 0.0;
//    }

//    for( ; j<columns; j++){
//	matrix.data[i][j] = 0.0;
//    }

  }
//  printf("matrix created\n\n");
  return matrix;
}

void print_matrix(Matrix matrix){
//  printf("printing matrix\n");

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
//  printf("freeing matrix...");
  int i;
  for(i=0; i+1<matrix.rows; i+=2){
    free(matrix.data[i]);
    free(matrix.data[i+1]);

  }

  for(; i < matrix.rows; i++){

    free(matrix.data[i]);
  }
  free(matrix.data);
//  printf("matrix has been freed\n\n");
}

//int main(){

//  Matrix matrix = create_matrix(8,7);
//  print_matrix(matrix);
//  free_matrix(matrix);
//  printf("end of program.\n");
//  return 0;
//}
