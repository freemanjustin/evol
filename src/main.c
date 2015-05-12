//  evol - a genetic algorithm code
//
// freeman.justin@gmail.com

#include "evol.h"

int main( int argc, char *argv[] )
{
	int				i,j;
	E 	*p; 					// pointer to parameter block
	agent 		*q;						// pointer to the genotype information
	agent		*r;						// pointer to the next generation
	unsigned 		rseed ;
    
#ifdef HAVEPGPLOT
	char			title[80];
	char			png_fname[80];
	float			**fcn;
	float			xval,yval;
#endif
    
	// check the command line args ...
	if ( argc != 2  &&  argc != 3 ){
	 	// not doing any file operations yet.
	 	// see artificial neural network code
	 	// for code to hande command line args
	 	// (modulo->main.c)
	}
    
	// Set the random seed 
	rseed = (unsigned)(time(NULL) % 65536L ); // Random seed from time
	sran4( rseed );

	// malloc memory for the run time parameters
	if ( (p = (E *)malloc( sizeof(E)) )== NULL){
		fprintf(stderr,"Error mallocing memory for the parameter struct.\n");
		exit(1);
	}

	// set the run time parameters...
	p->population = 50;				// number of agents in the population
	p->generations = 200;				// the number of evolutionary cycles

	p->mutation = 0.8;					// the probablility of mutation
	p->selection_pressure = 0.8;		// the probability of breeding. 0.6 means that only the top 40% get to breed.
	p->elitism = TRUE;						// fittest from previous generation stays in the population

	// data constraints
	
	p->x_max = 0.99;
	p->x_min = 0.01;
	
	p->y_max = 0.99;
	p->y_min = 0.01;
	
	p->z_max = 0.75;
	p->z_min = 0.25;
	
	/*
	// data constraints
	p->x_max = 100;
	p->x_min = -100;
	p->y_max = 100;
	p->y_min = -100;
	*/

#ifdef HAVEPGPLOT
	// for the visualisation
	p->imax = 256;
	p->jmax = 256;
    fcn = malloc2d ((p->imax)+1, (p->jmax)+1);
	for(i=0;i<p->imax;i++){
		for(j=0;j<p->jmax;j++){
			fcn[i][j] = (float)obj_func(((double)i/(double)p->imax),((double)j/(double)p->jmax), 0.0);
		}
	}
#endif
    
	// Set up some memory that is used to store values temporarily
	if ( (q=(agent *) malloc( sizeof(agent) * p->population )) == NULL){
		printf(	"\nError mallocing memory for the population.\n");
		exit(1);
	}
	// Set up some memory that is used to store values temporarily
	if ( (r=(agent *) malloc( sizeof(agent) * p->population )) == NULL){
		printf(	"\nError mallocing memory for the population.\n");
		exit(1);
	}

	// If we are here then we must be ready to do some serious execution

	// generate the initial population
	// remember to constrain the genes!
	for(i=0;i<p->population;i++){
		
		(q+i)->xVal = ran4();
		(q+i)->yVal = ran4();
		(q+i)->zVal = ran4();
		
		// apply constraints on parameter value space...
		if(  ( (q+i)->xVal < p->x_min) || ((q+i)->xVal > p->x_max) ){
		  //printf("xVal is out of range: i = %d, (q+i)->xVal = %f\n", i, (q+i)->xVal);
		  if(i == 0) i = 0;
		  else i--;
		}
		if(  ( (q+i)->yVal < p->y_min) || ((q+i)->yVal > p->y_max) ){
		  //printf("yVal is out of range: i = %d, (q+i)->yVal = %f\n", i, (q+i)->yVal);
		  if(i == 0) i = 0;
		  else i--;
		}
		if(  ( (q+i)->zVal < p->z_min) || ((q+i)->zVal > p->z_max) ){
		  //printf("yVal is out of range: i = %d, (q+i)->yVal = %f\n", i, (q+i)->yVal);
		  if(i == 0) i = 0;
		  else i--;
		}
	}

#ifdef HAVEPGPLOT
	// open a graphics surface
	if(cpgopen("/XSERVE") < 1)
		exit(1);
	
	/*
	if(cpgopen("/png") < 1)
		exit(1);
	*/
#endif
    
	fprintf(stdout,"#iteration\tx\ty\tz\tf\tave\terr\tsdev\tvar\n");
	for(j=0;j<(p->generations);j++){
		// determine fitness of population
		for(i=0;i<p->population;i++)
			(q+i)->fitness = obj_func((q+i)->xVal,(q+i)->yVal, (q+i)->zVal);

		// rank the population from weakest to strongest
		rank_population(p,q);
		
		// visualize
		// this will send the viz to a png file
		// make sure the correct device is selected above
		//sprintf(png_fname,"window%05d.png/PNG",j);
		//movie_frames(p,png_fname,fcn,1,title,q);
		
#ifdef HAVEPGPLOT
		sprintf(title,"Gen = %d Fit = %f Ave = %f",j,p->fittest,p->ave);
		movie(p,"temp_image.png/PNG",fcn,1,title);
		for(i=0;i<(p->population);i++){
			xval = (float)((q+i)->xVal)*(float)p->imax;
			yval = (float)((q+i)->yVal)*(float)p->jmax;
			cpgsch(1.5);
			//cpgpanl(1,1);
			//cpgsci(2);
			//cpgpt(1,&xval,&yval,16);
			//cpgpanl(1,2);
			cpgsci(3);
			cpgpt(1,&xval,&yval,18);
			cpgsch(1.0);
		}
		cpgsci(2);
		xval = (float)((q+(p->population-1))->xVal)*(float)p->imax;
		yval = (float)((q+(p->population-1))->yVal)*(float)p->jmax;
		cpgpt(1,&xval,&yval,18);
#endif
		//for(i=0;i<(p->population);i++)
		//      fprintf(stdout,"agent = %d\tx = %f\ty = %f\tobj_func = %f\n",i,(q+i)->xVal,(q+i)->yVal,obj_func((q+i)->xVal,(q+i)->yVal));
		
		fprintf(stdout,"%d\t%.8f\t%.8f\t%.8f\t%f\t%f\t%f\t%f\t%f\n", j, p->xVal, p->yVal, p->zVal, p->fittest, p->ave, fabs(p->ave-1.0), p->sdev, p->var);

        // and fprintf the population
        //for(i=0;i<(p->population);i++)
        //    fprintf(stdout,"agent = %d\tx = %f\ty = %f\tobj_func = %f\n",i,(q+i)->xVal,(q+i)->yVal,(q+i)->fitness);
        
		// generate the next population
		for(i=0;i<(p->population);i++)
			breed(p,q,r,i);			// breed parents via crossover and mutate the children
				
		if(p->elitism == TRUE){		// keep the best solution from the previous generation
			(r+(p->population -1))->xVal = (q+(p->population -1))->xVal;
			(r+(p->population -1))->yVal = (q+(p->population -1))->yVal;
			(r+(p->population -1))->zVal = (q+(p->population -1))->zVal;
		}

		for(i=0;i<(p->population);i++)
			copy_struct(p,i,q,i,r);
	}
	
	//fprintf(stdout,"\n\nEvolution Complete.\n");
	for(i=0;i<p->population;i++)
		(q+i)->fitness = obj_func((q+i)->xVal,(q+i)->yVal, (q+i)->zVal);

	// rank the agents
	rank_population(p,q);
    
    /*
	// and fprintf the population
	for(i=0;i<(p->population);i++)
		fprintf(stdout,"agent = %d\tx = %f\ty = %f\tobj_func = %f\n",i,(q+i)->xVal,(q+i)->yVal,(q+i)->fitness);
     */
    
	return(0);
}
