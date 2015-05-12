//  evol - a genetic algorithm code
//
// freeman.justin@gmail.com


#include "evol.h"

void breed(E *p, agent *q, agent *r, int i)
{
	double	rnum;
	int		parent1,parent2;
	char	gene_string1[GENE_LENGTH*DIMENSIONS+1],gene_string2[GENE_LENGTH*DIMENSIONS+1];
	char	daughter[GENE_LENGTH*DIMENSIONS+1];
	char	str1[GENE_LENGTH+1],str2[GENE_LENGTH+1], str3[GENE_LENGTH+1];
	
	// pick 2 parents from the 'fit' subgroup
	do {
		rnum = ran4();
		//printf("1: rnum = %f\n",rnum);
	}while(rnum < p->selection_pressure );

	parent1 = (int)((p->population)*rnum); 
	//fprintf(stdout,"parent1 was selected to be : %d\n",parent1);
	
	do {
		rnum = ran4();
		if ( (int)(p->population*rnum) == parent1) rnum = -1; // don't allow beeding with self
	}while(rnum < p->selection_pressure);
	
	parent2 = (int)((p->population)*rnum); 
	//fprintf(stdout,"parent2 was selected to be : %d\n",parent2);

	// encode genes to string
	sprintf(gene_string1,"%d%d%d",(int)(GENE_SCALE*(q+parent1)->xVal),(int)(GENE_SCALE*(q+parent1)->yVal),(int)(GENE_SCALE*(q+parent1)->zVal));
	sprintf(gene_string2,"%d%d%d",(int)(GENE_SCALE*(q+parent2)->xVal),(int)(GENE_SCALE*(q+parent2)->yVal),(int)(GENE_SCALE*(q+parent1)->zVal));
	//fprintf(stdout,"gene_srt1: %s\n",gene_string1);
	//fprintf(stdout,"gene_str2: %s\n",gene_string2);

	// perform a chromosome crossover (ie. breed a daughter)
	// and mutate...
	breed_xover(p,q,gene_string1,gene_string2);
	sprintf(daughter,"%s",gene_string1);
	//printf("daughter: %s\n", daughter);
	
	// decode the gene
	memcpy(str1,daughter,GENE_LENGTH);
	str1[GENE_LENGTH] = '\x0';
	memcpy(str2,&daughter[GENE_LENGTH],GENE_LENGTH);
	str2[GENE_LENGTH] = '\x0';
	memcpy(str3,&daughter[2*GENE_LENGTH],GENE_LENGTH);
	str3[GENE_LENGTH] = '\x0';
	//printf("decoded gene:\n");
	//printf("str1 = %s\n", str1);
	//printf("str2 = %s\n", str2);
	//printf("str3 = %s\n\n", str3);
	
	sscanf(str1,"%lf",&((r+i)->xVal));
	(r+i)->xVal = ((r+i)->xVal)/GENE_SCALE;
	sscanf(str2,"%lf",&((r+i)->yVal));
	(r+i)->yVal = ((r+i)->yVal)/GENE_SCALE;
	sscanf(str3,"%lf",&((r+i)->zVal));
	(r+i)->zVal = ((r+i)->zVal)/GENE_SCALE;
}
