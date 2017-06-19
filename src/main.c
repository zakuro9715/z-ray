#include <stdio.h>

#include "image.h"
#include "color.h"


int main()
{
    color_t c[10000];
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++)  {
            int i = y * 100 + x;
            c[i].x = x / 100.0;
            c[i].y = y / 100.0;
        }
    }
    save_ppm_image("out.pbm", c, 100, 100);
    return 0;
}   
