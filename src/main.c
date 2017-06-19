#include <stdio.h>

#include "image.h"
#include "color.h"


int main()
{
    image_t image = image_new(100, 100);
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++)  {
            int i = y * 100 + x;
            image.pixels[i].x = x / 100.0;
            image.pixels[i].y = y / 100.0;
        }
    }
    image_save_ppm("out.ppm", image);
    image_dispose(image);
    return 0;
}   
