#ifndef Z_RAY_da2078e914d445068bc013d4c6889717
#define Z_RAY_da2078e914d445068bc013d4c6889717

#include "intersection.h"
#include "object.h"
#include "ray.h"

typedef struct scene {
    object_t *objects;
} scene_t;

scene_t create_cornell_box_scene();

bool scene_intersect(scene_t scene, ray_t ray, intersection_t * out);

#endif
