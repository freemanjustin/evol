//  evol - a genetic algorithm code
//
// freeman.justin@gmail.com

#include "evol.h"

void get_stats(float *data, int n, float *ave, float *adev, float *sdev,
            float *var, float *skew, float *curt)
{
    int j;
    float ep=0.0,s,p;
    
    if (n <= 1) {
        fprintf(stderr,"Population too small to calc stats\n");
        exit(1);
    }
    s=0.0;
    for (j=0;j<n;j++) s += data[j];
    *ave=s/n;
    *adev=(*var)=(*skew)=(*curt)=0.0;
    for (j=0;j<n;j++) {
        *adev += fabs(s=data[j]-(*ave));
        ep += s;
        *var += (p=s*s);
        *skew += (p *= s);
        *curt += (p *= s);
    }
    *adev /= n;
    *var=(*var-ep*ep/n)/(n-1);
    *sdev=sqrt(*var);
    if (*var) {
        *skew /= (n*(*var)*(*sdev));
        *curt=(*curt)/(n*(*var)*(*var))-3.0;
    }
}