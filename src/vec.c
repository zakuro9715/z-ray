#include <math.h>
#include "vec.h"

double vec3_length_squared(vec3 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

double vec3_length(vec3 v)
{
    return sqrt(vec3_length_squared(v));
}
