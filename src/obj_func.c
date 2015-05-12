//  evol - a genetic algorithm code
//
// freeman.justin@gmail.com

#include "evol.h"

#define	n 	(11)

double	obj_func(double x, double y, double z)
{
	return (pow( (16.0*x*(1.0-x)*y*(1.0-y)*sin(n*M_PI*y)*sin(n*M_PI*x)), 2.0) );
	
}
