#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double sumx=0.0;
    double sumxsquared=0.0;

    unsigned n = 10000;
    double bias = 1000000000.0;//pow(10,9);
    //taken from the welford method example in homework2
    double m_oldM, m_newM, m_oldS, m_newS;
    int i;
    for (i=0; i<n; i++) {
        double r = (double) rand()/RAND_MAX+bias;

	if(i==0){
	    m_oldM = m_newM = r;
	    m_oldS = 0.0;
	}else{
	    m_newM = m_oldM + (r - m_oldM)/i;
	    m_newS = m_oldS + (r - m_oldM)*(r - m_newM);
	}

	m_oldM = m_newM;
	m_oldS = m_newS;
        //generate random number in [0,1]
       //printf("r=%f\n",r);
      // sumx+=r;
     // sumxsquared+=r*r;
    }
    //double var=(sumxsquared-sumx*sumx/n)/(n-1);
    double var = ((i>0) ? m_newS/(i-1):0.0);
    printf("variance=%f\n",var);
}
