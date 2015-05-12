//  evol - a genetic algorithm code
//
// freeman.justin@gmail.com

#include "evol.h"

#ifdef HAVEPGPLOT
void palett(int TYPE,float CONTRA,float BRIGHT)
{
//-----------------------------------------------------------------------
// Set a "palette" of colors in the range of color indices used by
// PGIMAG.
//-----------------------------------------------------------------------
      
      float 	GL[2], GR[2], GG[2], GB[2];
      float 	RL[9] = {-0.5, 0.0, 0.17, 0.33, 0.50, 0.67, 0.83, 1.0, 1.7},
      		 	RR[9] = {0.0, 0.0,  0.0,  0.0,  0.6,  1.0,  1.0, 1.0, 1.0}, 
      		 	RG[9] = {0.0, 0.0,  0.0,  1.0,  1.0,  1.0,  0.6, 0.0, 1.0}, 
      		 	RB[9] = {0.0, 0.3,  0.8,  1.0,  0.3,  0.0,  0.0, 0.0, 1.0};
      float 	HL[5] = {0.0, 0.2, 0.4, 0.6, 1.0}, 
      			HR[5] = {0.0, 0.5, 1.0, 1.0, 1.0}, 
      			HG[5] = {0.0, 0.0, 0.5, 1.0, 1.0}, 
      			HB[5] = {0.0, 0.0, 0.0, 0.3, 1.0};
      float 	WL[10] = {0.0, 0.5, 0.5, 0.7, 0.7, 0.85, 0.85, 0.95, 0.95, 1.0}, 
      			WR[10] = {0.0, 1.0, 0.0, 0.0, 0.3,  0.8,  0.3,  1.0,  1.0, 1.0}, 
      			WG[10] = {0.0, 0.5, 0.4, 1.0, 0.0,  0.0,  0.2,  0.7,  1.0, 1.0}, 
      			WB[10] = {0.0, 0.0, 0.0, 0.0, 0.4,  1.0,  0.0,  0.0, 0.95, 1.0};
      float 	AL[20] = {0.0, 0.1, 0.1, 0.2, 0.2, 0.3, 0.3, 0.4, 0.4, 0.5,
     			0.5, 0.6, 0.6, 0.7, 0.7, 0.8, 0.8, 0.9, 0.9, 1.0}, 
     			AR[20] = {0.0, 0.0, 0.3, 0.3, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0,
     			0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}, 
     			AG[20] = {0.0, 0.0, 0.3, 0.3, 0.0, 0.0, 0.0, 0.0, 0.8, 0.8,
     			0.6, 0.6, 1.0, 1.0, 1.0, 1.0, 0.8, 0.8, 0.0, 0.0}, 
     			AB[20] = {0.0, 0.0, 0.3, 0.3, 0.7, 0.7, 0.7, 0.7, 0.9, 0.9,
      			0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
      float 	BL[5] = {0.0, 0.2, 0.4, 0.6, 1.0}, 
      			BB[5] = {0.0, 0.5, 1.0, 1.0, 1.0}, 
      			BG[5] = {0.0, 0.0, 0.5, 1.0, 1.0}, 
      			BR[5] = {0.0, 0.0, 0.0, 0.3, 1.0};
      			
      float 	CL[9] = {0.0, 0.0, 0.17, 0.33, 0.50, 0.67, 0.83, 1.0, 1.7},
      		 	CR[9] = {0.0, 0.1,  0.2,  0.2,  0.3,  0.4,  0.5, 0.6, 1.7}, 
      		 	CG[9] = {0.0, 0.3,  0.5,  0.6,  0.7,  0.8,  0.9, 1.0, 1.0}, 
      		 	CB[9] = {0.0, 0.5,  0.7,  0.8,  0.85,  0.9,  0.95, 1.0, 1.0};

      GL[0] =0.0; GL[1] = 1.0;
      GR[0] =0.0; GR[1] = 1.0;
      GG[0] =0.0; GG[1] = 1.0;
      GB[0] =0.0; GB[1] = 1.0;
      

     
      if (TYPE==1) //  gray scale
         cpgctab(GL, GR, GG, GB, 2, CONTRA, BRIGHT);
      else if (TYPE==2) // rainbow
         cpgctab(RL, RR, RG, RB, 9, CONTRA, BRIGHT);
      else if (TYPE==3) //	 heat
         cpgctab(HL, HR, HG, HB, 5, CONTRA, BRIGHT);
      else if (TYPE==4) // weird IRAF
         cpgctab(WL, WR, WG, WB, 10, CONTRA, BRIGHT);
      else if (TYPE==5) // AIPS
         cpgctab(AL, AR, AG, AB, 20, CONTRA, BRIGHT);
      else if (TYPE==6) // blue
         cpgctab(BL, BR, BG, BB, 20, CONTRA, BRIGHT);
      else if (TYPE==7)	// experimental j map
		cpgctab(CL, CR, CG, CB, 9, CONTRA, BRIGHT);
      
     return;
}

void setvp()
{
//-----------------------------------------------------------------------
// Set the viewport, allowing margins around the edge for annotation.
// (This is similar in effect to PGVSTD, but has different margins.)
// The routine determines the view-surface size and allocates margins
// as fractions of the minimum of width and height.
//-----------------------------------------------------------------------
      float D, VPX1, VPX2, VPY1, VPY2;

      cpgsvp(0.0, 1.0, 0.0, 1.0);
      cpgqvp(1, &VPX1, &VPX2, &VPY1, &VPY2);
      D = (MIN(VPX2-VPX1, VPY2-VPY1))/40.0;
      VPX1 = VPX1 + 5.0*D;
      VPX2 = VPX2 - 2.0*D;
      VPY1 = VPY1 + 8.0*D;
      VPY2 = VPY2 - 2.0*D;
      cpgvsiz(VPX1, VPX2, VPY1, VPY2);
}

int image_cont(E *p, char* fname, float** val, int c_map)
{
	int i, j, k, lw, ci, ls;
  	float fmin, fmax,alev;
  	float *fort_array;
  	double x, y;
  	static float tr[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
  	float	bright, contra;

	if( (fort_array = (float*)malloc((p->imax+1)*(p->jmax+1)*sizeof(float))) == NULL)
	{
		fprintf(stderr,"malloc() failed in function image().\n");
		return -1;
	}
  	
	if (cpgopen(fname) < 1 )
    		exit(1);
    		
	fmin = 1e6;
	fmax = 0.0;
  	for (j=1; j<=(p->jmax); j++) {
    	for (i=1; i<=(p->imax); i++) {
      		k = (j-1)*(p->imax) + (i-1);	/* Fortran convention */
      		x = tr[0] + tr[1]*i + tr[2]*j;
      		y = tr[3] + tr[4]*i + tr[5]*j;
      		fort_array[k] = (float)val[i][j];
      		if (fort_array[k] < fmin) fmin = fort_array[k];
      		if (fort_array[k] > fmax) fmax = fort_array[k];
    	}
  	}

  	// Clear the screen. Set up window and viewport. 
  	cpgbbuf();
  	cpgpage();
	//Clear the screen. Set up window and viewport.
	setvp();
    cpgwnad(0.0, 1.0+((float)p->imax), 0.0, 1.0+((float)p->jmax));
  
  	bright = 0.5;
  	contra  = 1.0;
  	palett(c_map, contra, bright);
  	cpgimag(fort_array,(p->imax),(p->jmax),1,(p->imax),1,(p->jmax),fmin,fmax,tr);

	for (i=1; i<21; i++) {
    alev = fmin + i*(fmax-fmin)/20.0;
    lw = (i%5 == 0) ? 3 : 1;
	ci = (i < 10)   ? 4 : 2;
    ls = (i < 20)   ? 2 : 1;
    cpgslw(lw);
    cpgsci(ci);
    cpgsls(ls);
    cpgcont(fort_array, (p->imax), (p->jmax), 1,(p->imax), 1, (p->jmax), &alev, -1, tr);
  	}

	cpgslw(1);
  	cpgsls(1);
  	cpgsci(1);

	cpgmtxt("t",1.0,0.0,0.0,"Image Title Text");
    cpgsch(0.6);
    cpgbox("bcntsi",0.0,0,"bcntsiv",0.0,0);
    cpgmtxt("b",3.0,1.0,1.0,"pixel number");
      
	cpgwedg("BI", 4.0, 5.0, fmin, fmax, "pixel value");
    cpgsch(1.0);
    
  	cpgebuf();

  	
  	return(0);
 }

 int contour_movie(E *p, char* fname, float** val, int c_map)
{
	int i, j, k, lw, ci, ls;
  	float fmin, fmax,alev;
  	float *fort_array;
  	double x, y;
  	static float tr[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
  	float	bright, contra;

	if( (fort_array = (float*)malloc((p->imax+1)*(p->jmax+1)*sizeof(float))) == NULL)
	{
		fprintf(stderr,"malloc() failed in function image().\n");
		return -1;
	}
  	
	if (cpgopen(fname) < 1 )
    		exit(1);
    		
	fmin = 1e6;
	fmax = 0.0;
  	for (j=1; j<=(p->jmax); j++) {
    	for (i=1; i<=(p->imax); i++) {
      		k = (j-1)*(p->imax) + (i-1);	/* Fortran convention */
      		x = tr[0] + tr[1]*i + tr[2]*j;
      		y = tr[3] + tr[4]*i + tr[5]*j;
      		fort_array[k] = (float)val[i][j];
      		if (fort_array[k] < fmin) fmin = fort_array[k];
      		if (fort_array[k] > fmax) fmax = fort_array[k];
    	}
  	}
  	//printf("fmin = %f\tfmax = %f\n",fmin,fmax);

  	// Clear the screen. Set up window and viewport. 
  	cpgpanl(1,3);
  	cpgbbuf();
  	cpgpage();
	//Clear the screen. Set up window and viewport.
	setvp();
    cpgwnad(0.0, 1.0+((float)p->imax), 0.0, 1.0+((float)p->jmax));
  
  	bright = 0.5;
  	contra  = 1.0;
  	palett(c_map, contra, bright);
  	//cpgimag(fort_array,(p->imax),(p->jmax),1,(p->imax),1,(p->jmax),fmin,fmax,tr);

	for (i=1; i<21; i++) {
    alev = fmin + i*(fmax-fmin)/20.0;
    lw = (i%5 == 0) ? 3 : 1;
	ci = (i < 10)   ? 4 : 2;		
    ls = (i < 20)   ? 2 : 1;
    cpgslw(lw);
    cpgsci(ci);				//		`set colour index' chooses a colour for the axes
				   			//   1 = black
				   			//   2 = red
				   			//   3 = green
				   			//   4 = blue
				   			//   5 = cyan
				   			//   6 = pink
				   			//   7 = yellow
				   			//   8 = orange
				   			
    cpgsls(ls);
    cpgcont(fort_array, (p->imax), (p->jmax), 1,(p->imax), 1, (p->jmax), &alev, -1, tr);
  	}

	cpgslw(1);
  	cpgsls(1);
  	cpgsci(1);

	cpgmtxt("t",1.0,0.0,0.0,"Image Title Text");
    cpgsch(0.6);
    cpgbox("bcntsi",0.0,0,"bcntsiv",0.0,0);
    cpgmtxt("b",3.0,1.0,1.0,"pixel number");
      
	//cpgwedg("BI", 4.0, 5.0, fmin, fmax, "pixel value");
    cpgsch(1.0);
    
  	cpgebuf();

  	cpgend();
  	return(1);
 }

int contour(E *p, char* fname, float** val, int c_map)
{
	int i, j, k, lw, ci, ls;
  	float fmin, fmax,alev;
  	float *fort_array;
  	double x, y;
  	static float tr[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
  	float	bright, contra;

	if( (fort_array = (float*)malloc((p->imax+1)*(p->jmax+1)*sizeof(float))) == NULL)
	{
		fprintf(stderr,"malloc() failed in function image().\n");
		return -1;
	}
  	
	if (cpgopen(fname) < 1 )
    		exit(1);
    		
	fmin = 1e6;
	fmax = 0.0;
  	for (j=1; j<=(p->jmax); j++) {
    	for (i=1; i<=(p->imax); i++) {
      		k = (j-1)*(p->imax) + (i-1);	/* Fortran convention */
      		x = tr[0] + tr[1]*i + tr[2]*j;
      		y = tr[3] + tr[4]*i + tr[5]*j;
      		fort_array[k] = (float)val[i][j];
      		if (fort_array[k] < fmin) fmin = fort_array[k];
      		if (fort_array[k] > fmax) fmax = fort_array[k];
    	}
  	}
  	//printf("fmin = %f\tfmax = %f\n",fmin,fmax);

  	// Clear the screen. Set up window and viewport. 
  	cpgbbuf();
  	cpgpage();
	//Clear the screen. Set up window and viewport.
	setvp();
    cpgwnad(0.0, 1.0+((float)p->imax), 0.0, 1.0+((float)p->jmax));
  
  	bright = 0.5;
  	contra  = 1.0;
  	palett(c_map, contra, bright);
  	//cpgimag(fort_array,(p->imax),(p->jmax),1,(p->imax),1,(p->jmax),fmin,fmax,tr);

	for (i=1; i<21; i++) {
    alev = fmin + i*(fmax-fmin)/20.0;
    lw = (i%5 == 0) ? 3 : 1;
	ci = (i < 10)   ? 4 : 2;		
    ls = (i < 20)   ? 2 : 1;
    cpgslw(lw);
    cpgsci(ci);				//		`set colour index' chooses a colour for the axes
				   			//   1 = black
				   			//   2 = red
				   			//   3 = green
				   			//   4 = blue
				   			//   5 = cyan
				   			//   6 = pink
				   			//   7 = yellow
				   			//   8 = orange
				   			
    cpgsls(ls);
    cpgcont(fort_array, (p->imax), (p->jmax), 1,(p->imax), 1, (p->jmax), &alev, -1, tr);
  	}

	cpgslw(1);
  	cpgsls(1);
  	cpgsci(1);

	cpgmtxt("t",1.0,0.0,0.0,"Image Title Text");
    cpgsch(0.6);
    cpgbox("bcntsi",0.0,0,"bcntsiv",0.0,0);
    cpgmtxt("b",3.0,1.0,1.0,"pixel number");
      
	//cpgwedg("BI", 4.0, 5.0, fmin, fmax, "pixel value");
    cpgsch(1.0);
    
  	cpgebuf();

  	cpgend();
  	return(1);
 }

 int image(E *p, char* fname, float** val, int c_map)
{
	int i, j, k;
  	float fmin, fmax;
  	float *fort_array;
  	double x, y;
  	static float tr[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
  	float	bright, contra;

	if( (fort_array = (float*)malloc((p->imax+1)*(p->jmax+1)*sizeof(float))) == NULL)
	{
		fprintf(stderr,"malloc() failed in function image().\n");
		return -1;
	}
  	
	if (cpgopen(fname) < 1 )
    		exit(1);

	fmin = 1e6;
	fmax = 0.0;
  	for (j=1; j<=(p->jmax); j++) {
    	for (i=1; i<=(p->imax); i++) {
      		k = (j-1)*(p->imax) + (i-1);	/* Fortran convention */
      		x = tr[0] + tr[1]*i + tr[2]*j;
      		y = tr[3] + tr[4]*i + tr[5]*j;
      		fort_array[k] = (float)val[i][j];
      		if (fort_array[k] < fmin) fmin = fort_array[k];
      		if (fort_array[k] > fmax) fmax = fort_array[k];
    	}
  	}
  	//printf("fmin = %f\tfmax = %f\n",fmin,fmax);

  	// Clear the screen. Set up window and viewport. 
  	cpgbbuf();
  	cpgpage();
	//Clear the screen. Set up window and viewport.
	setvp();
    cpgwnad(0.0, 1.0+((float)p->imax), 0.0, 1.0+((float)p->jmax));
  
  	bright = 0.5;
  	contra  = 1.0;
  	palett(c_map, contra, bright);

  	cpgimag(fort_array,(p->imax),(p->jmax),1,(p->imax),1,(p->jmax),fmin,fmax,tr);
  	

	cpgslw(1);
  	cpgsls(1);
  	cpgsci(1);

	cpgmtxt("t",1.0,0.0,0.0,"Image Title Text");
    cpgsch(0.6);
    cpgbox("bcntsi",0.0,0,"bcntsiv",0.0,0);
    cpgmtxt("b",3.0,1.0,1.0,"pixel number");
      
	cpgwedg("BI", 4.0, 5.0, fmin, fmax, "pixel value");
    cpgsch(1.0);
    
  	cpgebuf();

  	cpgend();
  	return(1);
 }

 int movie(E *p, char* fname, float** val, int c_map, char* title)
{
	int i, j, k, lw, ci, ls;
  	float fmin, fmax,alev;
  	float *fort_array;
  	double x, y;
  	static float tr[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
  	float	bright, contra;
	if( (fort_array = (float*)malloc((p->imax+1)*(p->jmax+1)*sizeof(float))) == NULL)
	{
		fprintf(stderr,"malloc() failed in function image().\n");
		return -1;
	}
  	
	fmin = 1e6;
	fmax = 0.0;
  	for (j=1; j<=(p->jmax); j++) {
    	for (i=1; i<=(p->imax); i++) {
      		k = (j-1)*(p->imax) + (i-1);	// Fortran convention 
      		x = tr[0] + tr[1]*i + tr[2]*j;
      		y = tr[3] + tr[4]*i + tr[5]*j;
      		fort_array[k] = (float)val[i][j];
      		if (fort_array[k] < fmin) fmin = fort_array[k];
      		if (fort_array[k] > fmax) fmax = fort_array[k];
    	}
  	}
	if(fmin == fmax)
		return(-1);

  	// Clear the screen. Set up window and viewport. 
  	//cpgpanl(1,1);
  	cpgbbuf();
  	cpgeras();
	//Clear the screen. Set up window and viewport.
	setvp();
    cpgwnad(0.0, 1.0+((float)p->imax), 0.0, 1.0+((float)p->jmax));
  
  	bright = 0.5;
  	contra  = 1.0;
  	palett(c_map, contra, bright);
  	cpgimag(fort_array,(p->imax),(p->jmax),1,(p->imax),1,(p->jmax),fmin,fmax,tr);

  	//cpgslw(1);
  	//cpgsls(1);
  	//cpgsci(1);

	//cpgmtxt("t",1.0,0.0,0.0,title);
    //cpgsch(0.6);
    //cpgbox("bcntsi",0.0,0,"bcntsiv",0.0,0);
    //cpgmtxt("b",3.0,1.0,1.0,"fluid cell");
      
	//cpgwedg("BI", 4.0, 5.0, fmin, fmax, "Non-dimensional Temperature");
    //cpgsch(1.0);
    
  	//cpgebuf();

	//cpgpanl(1,2);
	//cpgbbuf();
  	//cpgeras();
	//Clear the screen. Set up window and viewport.
	//setvp();
    //cpgwnad(0.0, 1.0+((float)p->imax), 0.0, 1.0+((float)p->jmax));
    
  	for (i=1; i<=11; i++) {
    alev = fmin + i*(fmax-fmin)/11.0;
    //lw = (i%5 == 0) ? 3 : 1;
	ci = (i <= 5)   ? 4 : 5;
    //ls = (i < 11)   ? 2 : 1;
    lw	=	3;
    //ci	=	2;
    ls 	= 	1;
    cpgslw(lw);
    cpgsci(ci);						//		`set colour index' chooses a colour for the axes
				   					//   1 = black
				   					//   2 = red
				   					//   3 = green
				   					//   4 = blue
				   					//   5 = cyan
				   					//   6 = pink
				   					//   7 = yellow
				   					//   8 = orange
    	
    cpgsls(ls);
    //cpgcons(fort_array, (p->imax), (p->jmax), 1,(p->imax), 1, (p->jmax), &alev, -1, tr);
  	}
	cpgslw(1);
  	cpgsls(1);
  	cpgsci(1);
	cpgmtxt("t",1.0,0.0,0.0,title);
    cpgsch(0.6);
    cpgbox("bcntsi",0.0,0,"bcntsiv",0.0,0);
    //cpgmtxt("b",3.0,1.0,1.0,"fluid cell");
	cpgebuf();

	free((void*)fort_array);
  	return(0);
 }

 int vector_movie(E *p, char *fname, float** u, float **v)
{
	int i, j, k;
  	float *xvals,*yvals;
  	double x, y;
  	static float tr[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 1.0};

	if( (xvals = (float*)malloc((p->imax+1)*(p->jmax+1)*sizeof(float))) == NULL)
	{
		fprintf(stderr,"malloc() failed in function image().\n");
		return -1;
	}
	if( (yvals = (float*)malloc((p->imax+1)*(p->jmax+1)*sizeof(float))) == NULL)
	{
		fprintf(stderr,"malloc() failed in function image().\n");
		return -1;
	}

   	for (j=1; j<=(p->jmax); j++) {
    	for (i=1; i<=(p->imax); i++) {
      		k = (j-1)*(p->imax) + (i-1);	// Fortran convention 
      		x = tr[0] + tr[1]*i + tr[2]*j;
      		y = tr[3] + tr[4]*i + tr[5]*j;
      		xvals[k] = (float)u[i][j];
      		yvals[k] = (float)v[i][j];
    	}
  	}
	//if(fmin == fmax)
	//	return(-1);
	cpgpanl(1,3);
  	// Clear the screen. Set up window and viewport. 
  	cpgbbuf();
  	cpgeras();
	//Clear the screen. Set up window and viewport.
	setvp();
    cpgwnad(0.0, 1.0+((float)p->imax), 0.0, 1.0+((float)p->jmax));
  	
  	//cpgvstd();
  	//cpgsah(2,45.0,0.7);
   	cpgsch(0.3);
   	cpgsci(8);
  	cpgvect(xvals,yvals,(p->imax),(p->jmax),1,(p->imax),1,(p->jmax),0.0,0,tr,10.0);
	cpgsch(1.0);
	cpgslw(1);
  	cpgsls(1);
  	cpgsci(1);

	cpgmtxt("t",1.0,0.0,0.0,"Velocity Field");
    cpgsch(0.6);
    cpgbox("bcntsi",0.0,0,"bcntsiv",0.0,0);
    cpgmtxt("b",3.0,1.0,1.0,"fluid cell");
      
    cpgsch(1.0);
    
  	cpgebuf();

	free((void*)xvals);
	free((void*)yvals);
  	return(1);
 }

 int jvector(E *p, char *fname, float** u, float **v)
{
	int i, j, k;
  	float *xvals,*yvals;
  	double x, y;
  	static float tr[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 1.0};

	if( (xvals = (float*)malloc((p->imax+1)*(p->jmax+1)*sizeof(float))) == NULL)
	{
		fprintf(stderr,"malloc() failed in function image().\n");
		return -1;
	}
	if( (yvals = (float*)malloc((p->imax+1)*(p->jmax+1)*sizeof(float))) == NULL)
	{
		fprintf(stderr,"malloc() failed in function image().\n");
		return -1;
	}

   	for (j=1; j<=(p->jmax); j++) {
    	for (i=1; i<=(p->imax); i++) {
      		k = (j-1)*(p->imax) + (i-1);	// Fortran convention 
      		x = tr[0] + tr[1]*i + tr[2]*j;
      		y = tr[3] + tr[4]*i + tr[5]*j;
      		xvals[k] = (float)u[i][j];
      		yvals[k] = (float)v[i][j];
    	}
  	}
  	if (cpgopen(fname) < 1 )
    		exit(1);
    		
	//if(fmin == fmax)
	//	return(-1);
  	// Clear the screen. Set up window and viewport. 
  	cpgbbuf();
  	cpgeras();
	//Clear the screen. Set up window and viewport.
	setvp();
    cpgwnad(0.0, 1.0+((float)p->imax), 0.0, 1.0+((float)p->jmax));
  	
  	//cpgvstd();
  	//cpgsah(2,45.0,0.7);
   	cpgsch(0.3);
   	
  	cpgvect(xvals,yvals,(p->imax),(p->jmax),1,(p->imax)-1,1,(p->jmax)-1,0.0,0,tr,10.0);
	cpgsch(1.0);
	cpgslw(1);
  	cpgsls(1);
  	cpgsci(1);

	cpgmtxt("t",1.0,0.0,0.0,"Velocity Field");
    cpgsch(0.6);
    cpgbox("bcntsi",0.0,0,"bcntsiv",0.0,0);
    cpgmtxt("b",3.0,1.0,1.0,"fluid cell");
      
    cpgsch(1.0);
    
  	cpgebuf();

	cpgend();
	free((void*)xvals);
	free((void*)yvals);
  	return(1);
 }
 
 
  int movie_frames(E *p, char* fname, float** val, int c_map, char* title, agent *q)
{
	int i, j, k, lw, ci, ls;
  	float fmin, fmax,alev;
  	float *fort_array;
	float xval, yval;
  	double x, y;
  	static float tr[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
  	float	bright, contra;
	if( (fort_array = (float*)malloc((p->imax+1)*(p->jmax+1)*sizeof(float))) == NULL)
	{
		fprintf(stderr,"malloc() failed in function image().\n");
		return -1;
	}
  	
	if (cpgopen(fname) < 1 )
    		exit(1);
	
	fmin = 1e6;
	fmax = 0.0;
  	for (j=1; j<=(p->jmax); j++) {
    	for (i=1; i<=(p->imax); i++) {
      		k = (j-1)*(p->imax) + (i-1);	// Fortran convention 
      		x = tr[0] + tr[1]*i + tr[2]*j;
      		y = tr[3] + tr[4]*i + tr[5]*j;
      		fort_array[k] = (float)val[i][j];
      		if (fort_array[k] < fmin) fmin = fort_array[k];
      		if (fort_array[k] > fmax) fmax = fort_array[k];
    	}
  	}
	if(fmin == fmax)
		return(-1);

  	// Clear the screen. Set up window and viewport. 
  	//cpgpanl(1,1);
  	cpgbbuf();
  	cpgeras();
	//Clear the screen. Set up window and viewport.
	setvp();
    cpgwnad(0.0, 1.0+((float)p->imax), 0.0, 1.0+((float)p->jmax));
  
  	bright = 0.5;
  	contra  = 1.0;
  	palett(c_map, contra, bright);
  	cpgimag(fort_array,(p->imax),(p->jmax),1,(p->imax),1,(p->jmax),fmin,fmax,tr);

  	//cpgslw(1);
  	//cpgsls(1);
  	//cpgsci(1);

	//cpgmtxt("t",1.0,0.0,0.0,title);
    //cpgsch(0.6);
    //cpgbox("bcntsi",0.0,0,"bcntsiv",0.0,0);
    //cpgmtxt("b",3.0,1.0,1.0,"fluid cell");
      
	//cpgwedg("BI", 4.0, 5.0, fmin, fmax, "Non-dimensional Temperature");
    //cpgsch(1.0);
    
  	//cpgebuf();

	//cpgpanl(1,2);
	//cpgbbuf();
  	//cpgeras();
	//Clear the screen. Set up window and viewport.
	//setvp();
    //cpgwnad(0.0, 1.0+((float)p->imax), 0.0, 1.0+((float)p->jmax));
    
  	for (i=1; i<=11; i++) {
    alev = fmin + i*(fmax-fmin)/11.0;
    //lw = (i%5 == 0) ? 3 : 1;
	ci = (i <= 5)   ? 4 : 5;
    //ls = (i < 11)   ? 2 : 1;
    lw	=	3;
    //ci	=	2;
    ls 	= 	1;
    cpgslw(lw);
    cpgsci(ci);						//		`set colour index' chooses a colour for the axes
				   					//   1 = black
				   					//   2 = red
				   					//   3 = green
				   					//   4 = blue
				   					//   5 = cyan
				   					//   6 = pink
				   					//   7 = yellow
				   					//   8 = orange
    	
    cpgsls(ls);
    //cpgcons(fort_array, (p->imax), (p->jmax), 1,(p->imax), 1, (p->jmax), &alev, -1, tr);
  	}
	cpgslw(1);
  	cpgsls(1);
  	cpgsci(1);
	cpgmtxt("t",1.0,0.0,0.0,title);
    cpgsch(0.6);
    cpgbox("bcntsi",0.0,0,"bcntsiv",0.0,0);
    //cpgmtxt("b",3.0,1.0,1.0,"fluid cell");
	cpgebuf();

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

	xval = (float)((q+(p->population-1))->xVal)*(float)p->imax;
	yval = (float)((q+(p->population-1))->yVal)*(float)p->jmax;
	cpgsch(1.5);
	//cpgpanl(1,1);
	//cpgsci(2);
	//cpgpt(1,&xval,&yval,16);
	//cpgpanl(1,2);
	cpgsci(2);
	cpgpt(1,&xval,&yval,18);
	cpgsch(1.0);


	cpgend();
	
	free((void*)fort_array);
  	return(1);
 }
#endif
 
