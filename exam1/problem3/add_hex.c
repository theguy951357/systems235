#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

  //getting characters and storing them one at a time
  printf("Enter the first int as a two-character hex value: ");
  int* input = (int*)malloc(4*sizeof(int));
  input[0] = getchar();
  input[1] = getchar();
//  printf("\n [0]%d [1]%d\n",input[0],input[1]);
  printf("Enter the second int as a two-character hex value: ");
  getchar();
  input[2] = getchar();
  input[3] = getchar();
//  printf("\n [2]%d [3]%d\n",input[2],input[3]);

  //converting hex to decimal equivalent.
  for(int i = 0; i<4; i++){
    if(input[i]>=48&&input[i]<=57){
        input[i]-=48;
      }else if(input[i]>=65&&input[i]<=70){
        input[i]-=55;
      }
  }
  //subtracting 1 to each ones place number so the 2s complimentwill be added by one
  input[1]--;
  input[3]--;
  if(input[1]<0){
    input[0]--;
    input[1]=15;
  }
  if(input[3]<0){
    input[2]--;
    input[3]=15;
  }

//  printf("\n [0]%d [1]%d\n",input[0],input[1]);
//  printf("\n [2]%d [3]%d\n",input[2],input[3]);

  //allocating memory for binary representation and flipping the 1s and 0s for the 2s compliment
  int* binary1 = (int*)malloc(8*sizeof(int));
  int* binary2 = (int*)malloc(8*sizeof(int));
  for(int i=3; i>=0;i--){
    int power = pow(2,i);
    if(power <= input[1]){
      input[1]-=power;
      binary1[i]=0;
    }else{
      binary1[i]=1;
    }

    power = pow(2,i);
    if(power <= input[3]){
      input[3]-=power;
      binary2[i]=0;
    }else{
      binary2[i]=1;
    }
  }

  for(int i = 7; i>=4; i--){
    int power = pow(2,i%4);
    if(power<=input[0]){
      input[0]-=power;
      binary1[i]=0;
    }else{
      binary1[i]=1;
    }

    power = pow(2,i%4);
    if(power<=input[2]){
      input[2]-=power;
      binary2[i]=0;
    }else{
      binary2[i]=1;
    }

  }
  //adding binary together.
  int* sum = (int*)malloc(8*sizeof(int));
  int carry = 0;

  for(int i = 0;i<8;i++){
    int indexsum = binary1[i]+binary2[i]+carry;
//    printf("sum=%d",indexsum);
    carry=0;
//    if(sum[i]==0){
//      carry=1;
//    }
    if(indexsum==0){
      sum[i]=0;
    }
    if(indexsum == 1){
      sum[i]=1;
    }
    if(indexsum==2){
      sum[i]=0;
      carry=1;
    }
    if(indexsum==3){
      sum[i]=1;
      carry=1;
    }
  }
//  if(carry==0){
//    sum[9]=1;
//  }





  //converting sum to decimal.
  for(int i = 0; i < 8; i++){
    if(i<4){
      if(sum[i]==0){
	input[0]+=pow(2,i);
      }
    }else{
      if(sum[i]==0){
        input[1]+=pow(2,i%4);
      }
    }
  }
//  if(sum[9]==1){
//    input[1]+=pow(2,9);
//  }

  //adding to number to convert back from 2s comliment
  for(int i = 0;i<1; i++){

    input[0]++;
    if(input[0]==16){
      input[1]++;
      input[0]=0;
    }
  }

  //converting decimal to hexadecimal.
  for(int i = 0; i<2;i++){
    if(input[1]<16){
      if (input[i]<10){
        input[i]+=48;
      }else{
        input[i]+=55;
      }
    }else{
      input[i]=88;
    }
  }

  //printing binary arrays
//  for(int i = 7;i>=0;i--){
//    printf("%d", binary1[i]);
//  }
//  printf("\n");

//  for(int i = 7;i>=0;i--){
//    printf("%d", binary2[i]);
//  }
//  printf("\ncarry=%d\n",carry);


//  for(int i = 7;i>=0;i--){
//    printf("%d", sum[i]);
//  }
//  printf("\n");

  printf("The sum is: %c%c\n",input[1],input[0]);
  return 0;

  //freeing mallocs
  free(input);
  free(binary1);
  free(binary2);
  free(sum);
}
