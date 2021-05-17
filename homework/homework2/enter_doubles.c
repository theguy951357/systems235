#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "mean_and_var.h"
#define SIZE 100
#define BUFSIZE 100
#define TRUE 1
#define FALSE 0

char buf[BUFSIZE];
int bufp=0;

int getch(void) /* get a (possibly
pushed back) character */ {
    if (bufp > 0)
    {
        return buf[--bufp];
    }
    else
    {
        return getchar();
    }
}

void ungetch(int c) /* push character back on input */ {
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
/* getdouble: get next double from input to *pn */
double getdouble(double *pn)
{
    int sign;
    int point = FALSE;
    double c;
    double decimal=1;

    while (isspace(c = getch())) // skip whitespace
        ;
    //added '.' to the characters allowed in the if statement.
    if (!isdigit(c) && c != EOF && c != '+' && c != '-'&& c != '.') {
        c =getch();
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    //if a '.' is found, activate the point variable to true.
    if(c=='.'){
      c=getch();
      }
    //make sure for loop looks for the point, but does not add it
    //if point variable is true, multiply decimal by 10 and divide c by decimal.
    for (*pn = 0; isdigit(c)||c=='.'; c = getch()) {

      if(c=='.'){
	point = TRUE;
      }

      if(c!= '.'){
          *pn = 10 * *pn + (c - '0');
        if(point == TRUE){
          decimal *=10;
        }
      }

    }
    *pn *= sign;
    *pn /= decimal;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

int main(){

 // printf("Enter numbers, press ctrl-d to quit ");
  int size = 2;
  int count = 0;
  //getint(&size);
 // printf("size = %d\n",size);
  double *arr = (double*) malloc(size*sizeof(double));
  double *temp;

  for(int i = 0; getdouble(&arr[i]) != EOF; i++){

	//printf("arr[%d]=%f\n",i,arr[i]);
	  if(i>=size-1){
		 size*=2;
		 temp = (double*) malloc(size*sizeof(double));
		 for(int j=0;j<(size/2);j++){
		   temp[j]=arr[j];
		 }
		 free(arr);
		 arr = temp;
		//arr = realloc(arr, size*sizeof(double));
	  }
    count++;

  }

  printf("capacity=%d\n", size);
  printf("n=%d\n", count);

  for(int i = 0; i < count; i++){
    printf("array[%d]=%f\n",i,arr[i]);

  }

  printf("mean=%f\n", mean(arr,count));
  printf("var=%f\n", var(arr,count));


  free(arr);


  return 0;
}
