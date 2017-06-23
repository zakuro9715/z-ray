#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"
#include "math_utils.h"
 
image_t image_new(size_t width, size_t height)
{
    color_t *pixels = malloc(height * width * sizeof(color_t));
    memset(pixels, 0, height * width * sizeof(color_t));
    return (image_t) {
        .width = width,
        .height = height,
        .pixels = pixels
    };
}

void image_dispose(image_t image)
{
    free(image.pixels);
}

size_t image_size(image_t image)
{
    return image.width * image.height;
}

void image_save_ppm(const char * filename, image_t image)
{
    FILE *f = fopen(filename, "wb");
	fprintf(f, "P3\n%zd %zd\n%d\n", image.width, image.height, 255);
	for (int i = 0; i < image_size(image) ; i++)
    {
		fprintf(
            f, "%d %d %d ",
            ratio_to_int(clamp(image.pixels[i].x, 0.0, 1.0), 255),
            ratio_to_int(clamp(image.pixels[i].y, 0.0, 1.0), 255),
            ratio_to_int(clamp(image.pixels[i].z, 0.0, 1.0), 255)
        );
    }
    fclose(f);
}
