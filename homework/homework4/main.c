#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "initialCondition.h"
#include "write_pgm.h"


void setInitialCondition(Matrix matrix){
	for(int i = 0; i < matrix.rows; i++){
		for(int j = 0; j < matrix.columns; j++){
			double x = 1.0/(matrix.rows-1)*i;
			double y = 1.0/(matrix.columns-1)*j;
			matrix.data[i][j]= initialCondition(x,y);
		}
	}

}

void step(double k, double h, Matrix tip1, Matrix ti, Matrix tim1){
	for(int row = 1; row< tip1.rows-1; row++){
		for(int col = 1; col< tip1.columns-1; col++){
			tip1.data[row][col] = k*k/(h*h)*(ti.data[row-1][col]-4*ti.data[row][col]+ti.data[row+1][col]+ti.data[row][col-1]+ti.data[row][col+1]) +2*ti.data[row][col] - tim1.data[row][col];
		}
	}

}


int main(int arg, char* argv[]){

	double h = atof(argv[1]);
	double k = atof(argv[2]);
	double endTime = atof(argv[3]);
	int printEveryNSteps = atoi(argv[4]);
	int printEveryNPoints = atoi(argv[5]);

	char* filenamePrefix;
	if(arg >5){
		filenamePrefix = argv[6];
	}

	if(k>=h){
		fprintf(stderr, "error, cf1 condition violated");
	}

	int N = (int) (1.0/h)+1;

	Matrix matrix = create_matrix(N,N);
	setInitialCondition(matrix);
	char fileName[20];
	sprintf(fileName, "%06d.pgm",0);
	//creating matrix array of 3 matrices to use in the step method
	Matrix *states = malloc(3*sizeof(Matrix));
	states[0] = create_matrix(N,N);
	setInitialCondition(states[0]);
	states[1] = create_matrix(N,N);
	setInitialCondition(states[1]);
	states[2] = create_matrix(N,N);
	//writing initial matrix to pgm file.
	write_pgm(states[0],printEveryNPoints, fileName);


	int steps = 1;
	double t = 0.0;
	while(t<=endTime){
		//reindex the states
		Matrix uk = states[(steps+1)%3];//current
		Matrix ukm1 = states[steps%3];//previous
		Matrix ukm2 = states[(steps-1)%3];//previous previous

		step(k,h,uk,ukm1,ukm2);

		if(steps%printEveryNSteps == 0){
			sprintf(fileName, "%06d.pgm", steps/printEveryNSteps);
			write_pgm(uk,printEveryNPoints, fileName);
		}
		++steps;
		t = k*steps;

	}

	free(states);
	return 0;

}

