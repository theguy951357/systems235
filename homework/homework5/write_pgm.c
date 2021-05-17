#include <stdio.h>
#include "matrix.h"
#include <math.h>
//#include "read_data.h"
//fabs for float absolute value

void write_pgm(Matrix matrix,int printEveryNPoints, char* output){
  //loop through the matrix to fine the absolute value of the max float in the matrix
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
  int range = (254/(max-min));
  int size = ceil((float) matrix.rows/printEveryNPoints);
  //open a file to write to
  FILE *fp;
  fp = fopen(output, "w");
  //printing header
  fprintf(fp, "P2\n");
  fprintf(fp, "%d %d\n255\n", size, size);




  //set the numbers in the matrix to a range of 0-255 and print them to the file.


  for(int i = 0; i < matrix.rows; i+= printEveryNPoints){
    for(j=0; j+printEveryNPoints<matrix.columns; j+= (printEveryNPoints*2)){
        	fprintf(fp , "%d ", (int)ceil((matrix.data[i][j] - min)*range));
        	fprintf(fp , "%d ", (int)ceil((matrix.data[i][j+printEveryNPoints] - min)*range));


    }

    for(; j< matrix.columns; j+= printEveryNPoints){

        	fprintf(fp , "%d", (int)ceil((matrix.data[i][j] - min)*range));

    }
    fprintf(fp, "\n");
  }

  fclose(fp);
  printf("file = %s\n", output);
}


