#ifndef Z_RAY_06b304be6ab04309b06265e2910539e7
#define Z_RAY_06b304be6ab04309b06265e2910539e7

#include "vec.h"

typedef struct camera {
    vec3_t position, dir, up;
    double screen_dist, screen_width, screen_height;
} camera_t;

#endif
