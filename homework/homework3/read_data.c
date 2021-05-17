#include "matrix.h"
#include "read_data.h"
#include <stdio.h>
#include<stdlib.h>

Matrix import_data(char* str){
  printf("pulling data from %s\n", str);
  Matrix matrix;
  unsigned rows = 0;
  unsigned columns = 0;
  //opening file
  FILE *fp;
  fp=fopen(str, "r");
  int c = getc(fp);
  //counting number of rows and columns
  while(c!=EOF){
//    printf("%c",c);
    if(c==' '){
      columns++;
    }
    if(c=='\n'){
      rows++;
      columns++;
    }
    c=getc(fp);
  }
  columns/=rows;
  fclose(fp);

  //creating a new matrix with the rows and columns counted from previous loop
  matrix = create_matrix(rows, columns);
  fp = fopen(str,"r");
  char buff[100];
  double d;
  //assigning each data point with the  numbers read from the data
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      c=fscanf(fp, "%s", buff);
      d=atof(buff);
      matrix.data[i][j]= d;
    }
  }
//  print_matrix(matrix);
//  free_matrix(matrix);
  printf("matrix created from %s\n", str);
  return matrix;
}


//int main(){

//  import_data("x.txt");
//  printf("read_data finished\n");

//return 0;
//}
