#include <stdio.h>


double mean(double* values, unsigned size){
  double sum = 0.0;
  for(int i = 0; i < size; i++){
    sum+= values[i];

  }

  return sum/size;
}


double var(double* values, unsigned size){

  double sum = 0.0;
  double varmean = mean(values, size);
  for(int i = 0; i<size; i++){
    sum += ((values[i]-varmean)*(values[i]-varmean));
  }

  return sum/(size-1);


}
