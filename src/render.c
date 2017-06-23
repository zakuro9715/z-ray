#include <math.h>
#include <stdio.h>

#include "intersection.h"
#include "math_utils.h"
#include "random.h"
#include "ray.h"
#include "render.h"
#include "vec.h"

const int MIN_DEPTH = 6;
const int DEPTH_LIMIT = 48;

color_t calc_radiance(scene_t scene, ray_t ray, int depth) {
    intersection_t intersection;
    if (!scene_intersect(scene, ray, &intersection)) {
        return (color_t) { .x = 0, .y = 0, .z = 0 };
    }

    object_t * obj = scene_find_object(scene, intersection.object_id);
    vec3_t orienting_normal = vec3_dot(intersection.hit.normal , ray.dir) < 0.0
        ? intersection.hit.normal
        : vec3_multiple(intersection.hit.normal, -1.0);
	
    double probability = fmax(fmax(obj->material.color.x, obj->material.color.y), obj->material.color.z);
    if (depth > DEPTH_LIMIT)
	{
        probability *= pow(0.5, depth - DEPTH_LIMIT);
    }
    if (depth <= MIN_DEPTH)
    {
        probability = 1.0;
    }

    if (random_next() > probability)
    {
        return obj->material.emission;
    }

    color_t incoming_radiance, weight = { 1, 1, 1 };
    switch(obj->material.reflection_type)
    {
        case REFLECTION_TYPE_LAMBERT:;
		    vec3_t w = orienting_normal, u, v;
		    u = fabs(w.x) > EPS
                ? vec3_normalize(vec3_cross(VEC3_UP   , w))
			    : vec3_normalize(vec3_cross(VEC3_RIGHT, w));
		    v = vec3_cross(w, u);

		    double r1 = 2 * PI * random_next();
		    double r2  = random_next();
            double r2s = sqrt(r2);
		    vec3_t dir = vec3_normalize(
                vec3_add(
			        vec3_add(
                        vec3_multiple(u, cos(r1) * r2s),
			            vec3_multiple(v, sin(r1) * r2s)
                    ),
                    vec3_multiple(w, sqrt(1.0 - r2))
                )
            );

		    incoming_radiance = calc_radiance(scene, (ray_t) { .origin = intersection.hit.point, .dir = dir }, depth + 1);
	    	weight = vec3_devide(obj->material.color, probability);
    }

    return vec3_add(
        obj->material.emission,
        (vec3_t) {
            .x = incoming_radiance.x * weight.x,
            .y = incoming_radiance.y * weight.y,
            .z = incoming_radiance.z * weight.z
        }
    );
}

image_t render(camera_t camera, scene_t scene, size_t width, size_t samples, size_t supersamples)
{
    size_t height = camera.screen_height * (width / camera.screen_width);
    image_t image = image_new(width, height);

    vec3_t camera_dir, camera_up;
    camera_dir = vec3_normalize(camera.dir);
    camera_up = vec3_normalize(camera.up);

    vec3_t screen_x = vec3_multiple(vec3_normalize(vec3_cross(camera_dir, camera_up)), camera.screen_width);
	vec3_t screen_y = vec3_multiple(vec3_normalize(vec3_cross(screen_x, camera_dir)), camera.screen_height);
	vec3_t screen_center = vec3_add(camera.position, vec3_multiple(camera_dir, camera.screen_dist));
    
    #pragma omp parallel for
    for(int y = 0; y < (size_t)height; y++)
    {
        printf("\r[%3d%%] rendering...", y * 100 / (int)height);
        fflush(stdout);

        for(int x = 0; x < (size_t)width; x++)
        {
            size_t pixel_i = (height - y - 1) * width + x;
            for (int sy = 0; sy < supersamples; sy++)
            {
                for (int sx = 0; sx < supersamples; sx++)
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
                        rad = calc_radiance(scene, (ray_t) { .origin = camera.position, .dir = dir}, 0);

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
