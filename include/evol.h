//  evol - a genetic algorithm code
//
// freeman.justin@gmail.com


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <math.h>
#include <time.h>
#include <signal.h>
#include <ctype.h>

//#include "nrutil.h"
#include "rand.h"
#ifdef HAVEPGPLOT
#include "cpgplot.h"
#endif

#define FALSE (0)
#define TRUE  (1)


#define	MAX(a,b)	( ((a) > (b)) ? (a) : (b) )
#define	MIN(a,b)	( ((a) < (b)) ? (a) : (b) )

#define GENE_LENGTH	(8)
#define GENE_SCALE	(1e8)

#define DIMENSIONS	(3)


// struct agent
typedef struct agent { 	double	xVal;
					double	yVal;
					double	zVal;
					double		fitness;
	       } agent ;	// agent consisting of chromosomes

// Set up a type that holds the run time parameters
typedef struct {
			int 	population;  	// number of agents in population 
			int 	generations;  	// number of generations we evolve for
			double	crossover;		// crossover probability 
			double	mutation; 		// how much mutation we have 
			int 	elitism; 		// persistence of the fittest?
			double	selection_pressure;	// who gets to breed?
			int		imax;
			int		jmax;
			float	fittest;
			float	ave;
			float	adev;
			float	sdev;
			float	var;
			float	skew;
			float	curt;
			double	x_max;
			double	x_min;
			double	y_max;
			double	y_min;
			double	z_max;
			double	z_min;

			double	xVal;
			double	yVal;
			double	zVal;
       } E ;

// function prototypes
double obj_func(double x, double y, double z);

void rank_population(E *p, agent *q);

void sort2(unsigned long n, float arr[], float brr[]);

void copy_struct(E *p, int m, agent *r, int n, agent *q);

void breed(E *p, agent *q, agent *r, int j);

void breed_xover(E *p, agent *q, char *genome1, char *genome2);

#ifdef HAVEPGPLOT
void setvp();

void palett(int TYPE,float CONTRA,float BRIGHT);

int image(E *p, char* fname, float** fort_array, int c_map);
int contour(E *p, char* fname, float** val, int c_map);
int contour_movie(E *p, char* fname, float** val, int c_map);
int image_cont(E *p, char* fname, float** val, int c_map);
int movie(E *p, char* fname, float** val, int c_map, char* title);
int vector_movie(E *p, char *fname, float** u, float **v);
int jvector(E *p, char *fname, float** u, float **v);
int movie_frames(E *p, char* fname, float** val, int c_map, char* title, agent *q);
#endif

float** malloc2d (int x, int y);

void get_stats(float *data, int n, float *ave, float *adev, float *sdev,
	float *var, float *skew, float *curt);

int compare(const void *p1, const void *p2);





