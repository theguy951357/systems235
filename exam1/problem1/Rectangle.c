#include <stdio.h>
#include "Point.h"
#include "Rectangle.h"

#define TRUE  1;
#define FALSE  0;


double area(Rectangle rect){
	printf("starting area.\n");
	double area = ((rect.b.y) - (rect.a.y)) * ((rect.b.x) - (rect.a.x));
	printf("area calculated\n");
	if(area < 0){
		area *= -1.0;
	}
	return area;
}

int bigger(Rectangle a, Rectangle b){

	printf("Starting Bigger\n");
	if(area(a)>area(b)){
		return TRUE;

	}else{
		return FALSE;

	}

}


