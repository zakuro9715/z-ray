#ifndef Z_RAY_69a0fba0e59a4bceafb8a74e22bcf014
#define Z_RAY_69a0fba0e59a4bceafb8a74e22bcf014

#include "color.h"

typedef struct image {
    size_t width, height;
    color_t *pixels;
} image_t;

image_t image_new(size_t width, size_t height);
void image_dispose(image_t image);

size_t image_size(image_t image);
void image_save_ppm(const char * filename, image_t image);

#endif
