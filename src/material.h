#ifndef Z_RAY_2778a02c5e964641b6ecd24eed28a17b
#define Z_RAY_2778a02c5e964641b6ecd24eed28a17b

#include "color.h"

#define REFLECTION_TYPE_LAMBERT 1

typedef struct material {
    color_t color, emission;
    char reflection_type;
} material_t;

#endif
