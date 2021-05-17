#include <stdio.h>
#include<string.h>

int main(){

  FILE *fp = fopen("hello.c","r");
  int c = getc(fp);
  while(c!=EOF){
    printf("%c ",c);
    c=getc(fp);
  }
  printf("\n");
  fclose(fp);

  fp = fopen("hello.c","r");
  char buff[100];
  c = fscanf(fp, "%s",buff);
  while(c!=EOF){
    printf("%s\n ",buff);
    c=fscanf(fp, "%s",buff);
  }
  printf("\n");
  fclose(fp);

  fp = fopen("hello.c","r");
  char *ch;
  ch=fgets(buff,100,fp);
  while(ch !=NULL){
  printf("%s\n",buff);
  ch = fgets(buff,100,fp);
  }
  printf("\n");
  fclose(fp);

  char str1[100]="Hello";
  char str2[]=", chris";
  strcat(str1,str2);//concat str2 onto str1 (str1 must be large enough)
  printf("%s\n",str1);
  return 0;
}
