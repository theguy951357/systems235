#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"
//printf("making rectangle struct\n");
typedef struct rectangle{
	Point a;
	Point b;

}Rectangle;

double area(Rectangle rect);
int bigger(Rectangle a, Rectangle b);

#endif
