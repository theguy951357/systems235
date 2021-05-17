
#include <stdio.h>
#include <stdlib.h>
#define MAX 100




int main(){
  char vals[MAX];
  double entrys[MAX];
  int count = 0;
  int vcount = 0;
  double entry;
  double sum=0;

  printf("Enter daily rainfall totals, one per line, use 'T' for trace, use '-1' to quit:\n");
  while(entrys[count] != -1){
    while (( vals[vcount]=getchar())!= '\n'){
     // printf("vals[%d]=%c\n",vcount, vals[vcount]);
      vcount ++;
    }
    vcount = 0;
    entrys[count] = atof(vals);
   // printf("entrys[%d]=%f\n",count, entrys[count]);
    if(entrys[count]==-1){
      break;

    }
    if(entrys[count]=='T'){
      entrys[count]= 0;



    }


    count++;
  }
      for(int i = 0; i<count; i++){
        sum += entrys[i];
      }


  printf("total rainfall: %f\n", sum);


}
