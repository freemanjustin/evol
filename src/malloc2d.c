//  evol - a genetic algorithm code
//
// freeman.justin@gmail.com

#include "evol.h"

// malloc memory for 2d arrays
//
//	imax =	cols
// 	jmax =	rows

float** malloc2d (int imax, int jmax)
{
	float**  matrix;
	int	j;

	//printf("from malloc2d: imax = %d\tjmax = %d\n",imax,jmax);
	// malloc rows
	if ( (matrix = (float**) malloc( sizeof(float*)*(jmax+3) ) ) == NULL ) 
	{				
		printf(	"\nNot enough memory for the grid.\n") ;
		exit(1) ;
	}
	// malloc cols
	for ( j=0 ; j<=jmax+2  ; j++ )
	{
		if ( ( matrix[j] =  (float*)malloc( sizeof(float)*(imax+2) ) ) == NULL ) 
		{				
			printf(	"\nNot enough memory for the cells.\n") ;
			exit(1) ;
		}
	} 
	//printf("malloc2d ok ...\n");
	return matrix;
	
}

//free memory for 2d arrays
void free2d (float** matrix, int x, int y)
{
	// unmalloc the arrays (be nice)
}

