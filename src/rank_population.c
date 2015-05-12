//  evol - a genetic algorithm code
//
// freeman.justin@gmail.com

#include "evol.h"

void rank_population(E *p, agent *q)
{
	int			i;
	float		*pop_vector;

	// malloc memory for the pop_vector
	if ( (pop_vector = (float *)malloc(sizeof(float)*(p->population)) ) == NULL){
		fprintf(stderr,"\nError in func rank_population - malloc failed.\n");
		exit(1);
	}

	// now sort them into ascending order (weakest to fittest)
    qsort( q, p->population, sizeof(agent), compare);
    
    // copy the fitness values into the pop_vector
    for(i=0;i<p->population;i++)
        pop_vector[i] = (float) ((q+i)->fitness);
    
	// calculate the population stats
	get_stats(pop_vector,(p->population), &(p->ave), &(p->adev), &(p->sdev), &(p->var), &(p->skew), &(p->curt));

	// store the current values of the best solution
	p->xVal = (q+(p->population -1))->xVal;
	p->yVal = (q+(p->population -1))->yVal;
	p->zVal = (q+(p->population -1))->zVal;
    
    // and the fittest for this generation
    p->fittest = (q+(p->population -1))->fitness;
}
