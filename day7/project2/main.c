#include <stdio.h>
#include "helper.h"
#include "helper2.h"
//#include "empty.h"//need to compile with -Isome_dir

//int double_it(int);//declare double it
//int quadruple_it(int);//declare quadruple it

int main(){
  int x = 4;
  int y = double_it(x);
  printf("y=%d\n",y);
  int z = quadruple_it(x);
  printf("z=%d\n",z);


}
