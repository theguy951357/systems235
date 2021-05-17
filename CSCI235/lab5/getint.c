#include <stdio.h>
#include <ctype.h>
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
/* getint: get next integer from input to *pn */ int getint(int *pn) 
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
