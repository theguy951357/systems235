#include <stdio.h>

int main(){
  char str1[] = "Hello";//pads with one 0 ('\0')
  char str2[10] = "chris";//pads rest with 0 ('\0')
  char str3[] = {'m','e','l','i','s','s','a'};//oops. need a '\0'
  char str4[] = {'t','o','b','y','\0'};//valid c-style string
  char str5[10]; //indeterminate values
  str5[0] = 'h';

  printf("str1 = %s\n", str1);
  printf("str2 = %s\n", str2);

  if(str2[7] == '\0'){
    printf("there is a null character\n");
  }
  printf("str3 = %s\n",str3);//might crash?
 // str2[10] = 'x';//might crash.
  str3[7] = 'X';
  printf("str2 = %s\n",str2);

  printf("str4 = %s\n",str4);
  printf("str5 = %s\n",str5);
  printf("str5[5] = %c\n",str5[5]);

  //str5 = str2;//not allowed

}
