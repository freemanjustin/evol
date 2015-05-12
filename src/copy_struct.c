//  evol - a genetic algorithm code
//
// freeman.justin@gmail.com


#include "evol.h"

void copy_struct(E *p, int m, agent *r, int n, agent *q)
{
	if ( (q+n)->xVal < p->x_min )
		(q+n)->xVal = p->x_min;
		
	if ( (q+n)->xVal > p->x_max )
		(q+n)->xVal = p->x_max;
		
	if ( (q+n)->yVal < p->y_min )
		(q+n)->yVal = p->y_min;
		
	if ( (q+n)->yVal > p->y_max )
		(q+n)->yVal = p->y_max;
	
	if ( (q+n)->zVal < p->z_min )
		(q+n)->zVal = p->z_min;
		
	if ( (q+n)->zVal > p->z_max )
		(q+n)->zVal = p->z_max;
	
	(r+m)->xVal = (q+n)->xVal;
	(r+m)->yVal = (q+n)->yVal;
	(r+m)->zVal = (q+n)->zVal;
	(r+m)->fitness = (q+n)->fitness;
}
