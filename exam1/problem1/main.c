#include <stdio.h>
#include "Point.h"
#include "Rectangle.h"
#include "Rectangle.h" // to test header guard

//program is segfaulting before it even starts. can't get it to not do that
int main() {
    ("beginning main\n");
    Rectangle r1 = {{1,-2},{2,3}};

    Point p1 = {3,3.5};
    Point p2 = {5,1.5};
    Rectangle r2 = {p1,p2};
    
    if (area(r1)==5.0) {
        printf("correct\n");
    } else {
        printf("incorrect\n");
    }

    if (area(r2)==4.0) {
        printf("correct\n");
    } else {
        printf("incorrect\n");
    }

    if (bigger(r1,r2)) {
        printf("correct\n");
    } else {
        printf("incorrect\n");
    }
}
