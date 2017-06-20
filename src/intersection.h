#ifndef Z_RAY_3eb8686e1bfb4db9a095f9c75138db74
#define Z_RAY_3eb8686e1bfb4db9a095f9c75138db74

#include "vec.h"

typedef struct ray_hit {
    double distance;
    vec3_t point, normal;
} ray_hit_t;

typedef struct intersection {
    ray_hit_t hit;
} intersection_t;

#endif
