#include <stdio.h>
#include<math.h>
#include <stdlib.h>

int  main(){
  int count = 0;
  int num;
  char  number[1];
  char min = '0';
  char max = '9';
  int vals[10];

  printf("Enter five digits, one at a time:\n");

  while(count<10){
      number[0] = getchar();
    if(number[0] >= min && number[0]<= max){

      num  =  atoi(number);
      vals[count] = num;
      count++; 

      continue;
    }else{

	vals[count] = 0;
        count++;

	continue;
    }



  }

      printf("vals contains:\n");
	count = 0;
      for(int i = 0; i <10; i+=2){
	printf("vals[%d]=%d, square=%d\n",count,vals[i],(int)pow(vals[i],2));
	count++;
   }


}
