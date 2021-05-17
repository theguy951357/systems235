#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double mean(double v[], int length){
	double sum = 0;
	double sum2 = 0;
	for(int i = 0; i!=length; i+=2){
		sum+=v[i];
		sum2+=v[i+1];
	}
	return (sum+sum2)/length;
}

double variance(double v[], int length){
	double sum=0;
	double sum2=0;
	double mu = mean(v,length);
	for(int i = 0; i != length; i+=2){
		sum+=(v[i]-mu)*(v[i]-mu);
		sum2+=(v[i+1]-mu)*(v[i+1]-mu);
	}
	return (sum+sum2)/(length-1);
}

int main(int argc, char **argv){
	unsigned n = atoi(argv[1]);//100000;
	double dat[n];
	clock_t start,end;
	double elapsed;

	for(int i = 0; i<n; i++){
		double r = (double) rand()/RAND_MAX;
		dat[i]=r;
	}
	start = clock();
	double var = variance(dat,n);
	end = clock();
	printf("n=%u\n",n);
	printf("variance=%f\n", var);
	elapsed = ((double) (end-start));
	printf("elapsed = %f\n", elapsed);
}
