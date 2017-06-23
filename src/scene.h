#ifndef Z_RAY_da2078e914d445068bc013d4c6889717
#define Z_RAY_da2078e914d445068bc013d4c6889717

#include "intersection.h"
#include "object.h"
#include "ray.h"

typedef struct scene {
    size_t objects_n;
    object_t * objects;
} scene_t;

scene_t create_cornell_box_scene();

void scene_malloc_objects(scene_t * scene, size_t n);
void scene_free_objects(scene_t * scene);

bool scene_intersect(scene_t scene, ray_t ray, intersection_t * out);
object_t * scene_find_object(scene_t scene, unsigned int id);

#endif
