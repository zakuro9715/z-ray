
#include "random.h"
#include <stdlib.h>
#include <stdint.h>

uint32_t xor128()
{
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w =  88675123;
    uint32_t t;

    t = x^ (x << 11);
    x = y;
    y = z;
    z = w;
    w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    return w;
}

double random_next()
{    
    return (double)xor128() / (double)(4294967295);
}
