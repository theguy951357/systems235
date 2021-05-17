#include <stdio.h>
#include "matrix.h"
#include <math.h>
//#include "read_data.h"
//fabs for float absolute value

void write_pgm(Matrix matrix,int printEveryNPoints, char* output){
  //open a file to write to
  double max = 0.0;

  int j;
  for(int i = 0; i< matrix.rows; i++){
    for(j = 0; j+1 < matrix.columns; j+=2){
      double j1 = fabs(matrix.data[i][j]);
      double j2 = fabs(matrix.data[i][j+1]);

      if(j1>max){max = j1;}
      if(j2>max){max = j2;}
    }
    for( ; j < matrix.columns; j++){
      double j1 = fabs(matrix.data[i][j]);

      if(j1>max){max = j1;}

    }
  }

  double min = -max;
  int size = ceil((float) matrix.rows/printEveryNPoints);
  //  printf("max=%f\nmin=%f\n",max,min);
  FILE *fp;
  fp = fopen(output, "w");
  //printing header
  fprintf(fp, "P2\n");
  fprintf(fp, "%d %d\n255\n", size, size);
 // Matrix pgmMatrix = create_matrix(size, size);
//  matrix.data[0][0]=-0.5;//testing to make sure number rounds up if needed.


  //set the numbers in the matrix to a range of 0-255 and print them to the file.
  for(int i = 0; i < matrix.rows; i+= printEveryNPoints){
    for(int j=0; j< matrix.columns; j+= printEveryNPoints){

//		pgmMatrix.data[i][j]=ceil((matrix.data[i][j] - min)*(254/(max - min)));
        	fprintf(fp , "%d", (int)ceil((matrix.data[i][j] - min)*(254/(max-min))));

		if(j!= matrix.columns-1){
        	  //fprintf(fp, "] [");//test to make sure no spaces were printed to the file at the end of each row.
        	  fprintf(fp, " ");
        	}

    }
    fprintf(fp, "\n");
  }

  fclose(fp);
  //free_matrix(pgmMatrix);
  printf("written to file %s\n", output);
}

//int main(){
//  Matrix matrix = import_data("x.txt");
//  write_pgm(matrix, "my_x.pgm");
//  free_matrix(matrix);
//  return 0;
//}
