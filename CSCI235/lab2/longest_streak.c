#include <stdio.h>

unsigned longest_streak(int nums[],unsigned size){


  if(size==0){return 0;}
  int count = 1;
  int highScore=0;
  for(int i = 0; i < size; i++){
   // printf("nums[%d]=%d\n",i,nums[i]);
    if(nums[i] == nums[i+1]&& nums [i+1] != '\0'&& nums[i+1] != EOF){

      for(int j = i+1; j <size; j++){

        if(nums[i] == nums[j]){

	count++;
        }
      }
    }

    if(count > highScore){
      highScore = count;
    }
    count = 1;
  }

  return highScore;


}
