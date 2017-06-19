#include "random.h"
#include <stdlib.h>

// TODO: Use better algorithm(XorShift, etc...)

double random_next()
{
    return (double)rand() / RAND_MAX;
}

unsigned int random_next_uint()
{
    return rand();
}
