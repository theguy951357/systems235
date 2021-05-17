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

  printf("How many numbers will you enter? ");
  int size;
  getint(&size);
 // printf("size = %d\n",size);
  int *arr = (int *) malloc(size*sizeof(int));

  for(int i = 0; i < size; i++){
    getint(&arr[i]);

  }

  for(int i = 0; i < size; i++){
    printf("array[%d]=%d\n",i,arr[i]);

  }

  free(arr);

  return 0;
}
