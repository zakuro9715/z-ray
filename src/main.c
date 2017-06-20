#include <stdio.h>
#include <stdlib.h>

#include "camera.h"
#include "color.h"
#include "image.h"
#include "render.h"
#include "material.h"
#include "object.h"
#include "scene.h"

int main()
{
    camera_t camera = {
        (vec3_t) { .x = 50.0, .y = 52.0 , .z = 220.0 },
	    (vec3_t) { .x = 0.0 , .y = -0.04, .z = -1.0  },
	    (vec3_t) { .x = 0.0 , .y =  1.0 , .z = 0.0   },
        40, 40, 30
    };

    scene_t scene = create_cornell_box_scene();

    image_t image = render(camera, scene, 100, 5, 10);
    image_save_ppm("out.ppm", image);
    image_dispose(image);

    free(scene.objects);

    return 0;
}   
