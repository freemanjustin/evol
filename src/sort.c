//  evol - a genetic algorithm code
//
// freeman.justin@gmail.com

#include "evol.h"

int compare(const void *p1, const void *p2){
    
    const struct agent *elem1 = p1;
    const struct agent *elem2 = p2;
    
    if ( elem1->fitness < elem2->fitness)
        return -1;
    else if (elem1->fitness > elem2->fitness)
        return 1;
    else
        return 0;
}

