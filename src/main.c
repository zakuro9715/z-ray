#include <stdio.h>

#include "camera.h"
#include "color.h"
#include "image.h"
#include "render.h"

int main()
{
    camera_t camera = {
        (vec3_t) { .x = 50.0, .y = 52.0 , .z = 220.0 },
	    (vec3_t) { .x = 0.0 , .y = -0.04, .z = -1.0  },
	    (vec3_t) { .x = 0.0 , .y =  1.0 , .z = 0.0   }
    };

    image_t image = render(camera, 100, 100, 1, 1);
    image_save_ppm("out.ppm", image);
    image_dispose(image);
    return 0;
}   
