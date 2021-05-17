#include <stdio.h>
#include <stdlib.h>//for atoi
#include <math.h> //compile with -lm(lower case L and M)

int main(){

  printf("sizeof(int) = %lu\n", sizeof(int));
  printf("sizeof(char) = %lu\n", sizeof(char));
  printf("sizeof(short) = %lu\n", sizeof(short));
  printf("sizeof(long) = %lu\n", sizeof(long));
  printf("sizeof(unsigned long) = %lu\n", sizeof(unsigned long));
  printf("sizeof(long long) = %lu\n", sizeof(long long));
  printf("sizeof(float) = %lu\n", sizeof(float));
  printf("sizeof(double) = %lu\n", sizeof(double));
  printf("sizeof(int32_t) = %lu\n", sizeof(int32_t));


  int x = 1234567;
  short y = x;
  printf("x=%d, y=%d\n",x,y);

  double z = 2.0;
  //double test = 2/4*10;//0
  //double test = 2.0/4*10;//5.0
  //double test = (double)2/4*10;//5.0
  double test = 2/4* (double)10;//0.00000
   printf("test = %f\n", test);


  enum sizes {SMALL, MEDIUM, LARGE};
  enum sizes tshirt = MEDIUM;
  enum sizes coffee = SMALL;
  printf("tshirt=%d\n",tshirt);
  printf("coffee=%d\n",coffee);

  char val[] = "123";
  int intval = atoi(val);//need to include <stdlib.h>
  printf("intval=%d\n", intval);

  int n = 1;
  printf("n=%d\n",n);
  printf("n++=%d\n",n++);//postfix increment operator (incremented after use)

  printf("n=%d\n",n);
  printf("++n=%d\n",++n);//prefix increment (before use)
  printf("n=%d\n",n);

  //math.h
  printf("2^3=%f\n",pow(2,3));
  printf("fabs(-3.3)=%f\n", fabs(-3.3));//fabs for floating point, abs for int.


  return 0;

}
