//  evol - a genetic algorithm code
//
// freeman.justin@gmail.com

#include "evol.h"

void breed_xover(E *p, agent *q, char *genome1, char *genome2)
{
	double		rnum;
	int			xover_point, mutation_point,mutation;
	int			i,j;
	char		daughter[80];
	char		mutation_srt[2];
	
	// randomly choose a crossover point
	rnum = ran4();
	xover_point = (int)ceil(GENE_LENGTH*rnum); // added the ceil() call so we never x-over at zero in the string
	//fprintf(stdout,"genome1: %s\tgenome2: %s\txover_point: %d\n",genome1,genome2,xover_point);

	// now xover the 2 strings to make the new offspring
	// either we copy genetic information from A->B or B->A.
	rnum = ran4();
	if(rnum < 0.5 ) {
		memcpy(&genome1[xover_point],&genome2[xover_point],(DIMENSIONS*GENE_LENGTH-xover_point));
		sprintf(daughter,"%s",genome1);
		//fprintf(stdout,"\nafter xover event:\n%s\t%s\ndaughter = %s\n",genome1,genome2,daughter);
	}
	else {
		memcpy(&genome2[xover_point],&genome1[xover_point],(DIMENSIONS*GENE_LENGTH-xover_point));
		sprintf(daughter,"%s",genome2);
		//fprintf(stdout,"\nafter xover event:\n%s\t%s\ndaughter = %s\n",genome1,genome2,daughter);
	}
	
	// now mutate a gene if the probability test is satisfied
	rnum = ran4();
	if(rnum < p->mutation) {
		rnum = ran4();
		j = (int)ceil(2*GENE_LENGTH*rnum);
		for(i=0;i<j;i++) {
			rnum = ran4();	// randomly pick a gene to mutate
			mutation_point = (int)(DIMENSIONS*GENE_LENGTH*rnum);
			rnum = ran4();	// now mutate that gene
			mutation = (int)floor(10.0*rnum); 	// mutation is an integer between 0 and 9 
			sprintf(mutation_srt,"%d",mutation);
			memcpy(&daughter[mutation_point],mutation_srt,1);
			//fprintf(stdout,"\n--- mutated a gene ---\ngene %d\t%s\n",mutation_point,daughter);
		}
	}
	sprintf(genome1,"%s",daughter);
}
