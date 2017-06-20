#ifndef Z_RAY_4da4aa8576c54bc69f4d51c07b807895
#define Z_RAY_4da4aa8576c54bc69f4d51c07b807895

#include <stdbool.h>

#include "intersection.h"
#include "material.h"
#include "ray.h"
#include "vec.h"

typedef unsigned int object_id_t;
typedef unsigned int object_type_t;

#define OBJECT_TYPE_SPHERE 1

typedef struct sphere {
    vec3_t center;
    double radius;
} sphere_t;

bool sphere_intersect(const sphere_t * sphere, ray_t ray, intersection_t *out);


typedef struct object {
    object_id_t id;
    object_type_t type;
    material_t material;
    union {
        sphere_t sphere;
    } u;
} object_t;

bool object_intersect(const object_t * object, ray_t ray, intersection_t * out);

#endif
