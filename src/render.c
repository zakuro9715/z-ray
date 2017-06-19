#include "render.h"
#include "ray.h"

#include <stdio.h>

color_t calc_radiance(ray_t ray, int depth) {
    return (color_t) { .x = 0.5, .y = 0, .z = 0 };
}


image_t render(camera_t camera, size_t width, size_t samples, size_t supersamples)
{
    size_t height = camera.screen_height * (width / camera.screen_width);
    image_t image = image_new(width, height);

    vec3_t screen_x = vec3_multiple(vec3_normalize(vec3_cross(camera.dir, camera.up)), camera.screen_width);
	vec3_t screen_y = vec3_multiple(vec3_normalize(vec3_cross(screen_x, camera.dir)), camera.screen_height);
	vec3_t screen_center = vec3_add(camera.position, vec3_multiple(camera.dir, camera.screen_dist));

    for(size_t y = 0; y < height; y++)
    {
        for(size_t x = 0; x < width; x++)
        {
            size_t pixel_i = y * width + x;
            for (size_t sy = 0; sy < supersamples; sy++)
            {
                for (size_t sx = 0; sx < supersamples; sx++)
                {
                    color_t accumulated_radiance = { 0, 0, 0 };
                    
					for (int s = 0; s < samples; s++)
                    {
						double rate = (1.0 / supersamples);
						double r1 = sx * rate + rate / 2.0;
						double r2 = sy * rate + rate / 2.0;
						
						vec3_t screen_position = vec3_add(
                            screen_center, 
							vec3_add(
                                vec3_multiple(screen_x, (r1 + x) / width - 0.5),
							    vec3_multiple(screen_y, (r2 + y) / height- 0.5)
                            )
                        );
						vec3_t dir = vec3_normalize(vec3_subtract(screen_position, camera.position));
                        color_t rad;
                        rad = calc_radiance((ray_t) { .origin = camera.position, .dir = dir}, 0);

						accumulated_radiance = vec3_add(
                            accumulated_radiance,
							vec3_devide(rad, samples * supersamples * supersamples)
                        );
                    }

                    image.pixels[pixel_i] = vec3_add(image.pixels[pixel_i], accumulated_radiance);
                    
                }
            } 
        }
    }

    return image;
}
