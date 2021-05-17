#include <stdio.h>
# include <ctype.h>
#include <stdlib.h>
#define SIZE 100
#define BUFSIZE 100

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
/* getint: get next integer from input to *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) // skip whitespace
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
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
  int *arr = (int *) malloc(size*sizeof(int));


  for(int i = 0; getint(&arr[i]) != EOF; i++){

	  if(i>=size-1){
		 size*=2;
		 arr = (int*) realloc(arr, size*sizeof(int));
	  }
   // getint(&arr[i]);
    count++;

  }

  printf("capacity= %d\n", size);
  printf("n= %d\n", count);

  for(int i = 0; i < count; i++){
    printf("array[%d]=%d\n",i,arr[i]);

  }

  free(arr);

  return 0;
}

