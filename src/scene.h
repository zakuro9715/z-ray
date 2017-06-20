#ifndef Z_RAY_da2078e914d445068bc013d4c6889717
#define Z_RAY_da2078e914d445068bc013d4c6889717

#include "object.h"

typedef struct scene {
    object_t *objects;
} scene_t;

scene_t create_cornell_box_scene();

#endif
