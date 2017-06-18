#include <stdio.h>

#include "image.h"
#include "math_utils.h"
 
void save_ppm_image(const char * filename, const color_t *image, const int width, const int height)
{
    FILE *f = fopen(filename, "wb");
	fprintf(f, "P3\n%d %d\n%d\n", width, height, 255);
	for (int i = 0; i < width * height; i++)
    {
		fprintf(
            f, "%d %d %d ",
            ratio_to_int(image[i].x, 255),
            ratio_to_int(image[i].y, 255),
            ratio_to_int(image[i].z, 255)
        );
    }
    fclose(f);
}
