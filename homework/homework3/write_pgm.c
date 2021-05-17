#include <stdio.h>
#include "matrix.h"
#include "read_data.h"
#define MAX 1
#define MIN 1

void write_pgm(Matrix matrix, char* output){
  //open a file to write to
  FILE *fp;
  fp = fopen(output, "w");
  fprintf(fp, "P2\n");
  fprintf(fp, "%d %d\n255\n", matrix.rows, matrix.columns);
  int datathing;
//  matrix.data[0][0]=-0.5;//testing to make sure number rounds up if needed.
  //set the numbers in the matrix to a range of 0-255 and print them to the file.
  for(int i = 0; i < matrix.rows; i++){
    for(int j=0; j< matrix.columns; j++){
      matrix.data[i][j]=(matrix.data[i][j] + MIN)*(254/(MAX + MIN));
      datathing = matrix.data[i][j];
      if (matrix.data[i][j]-datathing > 0.0){
	datathing++;
      }
      fprintf(fp , "%d", datathing);
      if(j!= matrix.columns-1){
        //fprintf(fp, "] [");//test to make sure no spaces were printed to the file at the end of each row.
        fprintf(fp, " ");
      }
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
  printf("written to file %s\n", output);
}

//int main(){
//  Matrix matrix = import_data("x.txt");
//  write_pgm(matrix, "my_x.pgm");
//  free_matrix(matrix);
//  return 0;
//}
