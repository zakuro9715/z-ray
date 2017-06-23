#include <stdlib.h>

#include "math_utils.h"
#include "scene.h"

scene_t create_cornell_box_scene()
{
    scene_t s;
    scene_malloc_objects(&s, 8);
    
    for (int i = 0; i < s.objects_n; i++)
    {
        s.objects[i].material.color    = (color_t) { .x = 0, .y = 0, .z = 0 };
        s.objects[i].material.emission = (color_t) { .x = 0, .y = 0, .z = 0 };
        s.objects[i].type = OBJECT_TYPE_SPHERE;
        s.objects[i].material.reflection_type = REFLECTION_TYPE_LAMBERT;
    }

    s.objects[0].u.sphere = (sphere_t){
        .radius = 1e5, 
        .center = (vec3_t) { .x = 1e5+1, .y = 40.8, .z = 81.6 }
    };
    s.objects[0].material.color = (color_t) { .x = 0.75, .y = 0.25, .z = 0.25 };
    

    s.objects[1].u.sphere = (sphere_t){
        .radius = 1e5, 
        .center = (vec3_t) { .x = -1e5+99, .y = 40.8, .z = 81.6 }
    };
    s.objects[1].material.color = (color_t) { .x = 0.25, .y = 0.25, .z = 0.75 };
    
    s.objects[2].u.sphere = (sphere_t){
        .radius = 1e5, 
        .center = (vec3_t) { .x = 50, .y = 40.8, .z = 1e5 }
    };
    s.objects[2].material.color = (color_t) { .x = 0.75, .y = 0.75, .z = 0.75 };

    s.objects[3].u.sphere = (sphere_t){
        .radius = 1e5, 
        .center = (vec3_t) { .x = 50, .y = 40.8, .z = -1e5+250 }
    };
    s.objects[3].material.color = (color_t) { .x = 0, .y = 0, .z = 0 };
    
    s.objects[4].u.sphere = (sphere_t){
        .radius = 1e5, 
        .center = (vec3_t) { .x = 50, .y = 1e5, .z = 81.6 }
    };
    s.objects[4].material.color = (color_t) { .x = 0.75, .y = 0.75, .z = 0.75 };

    s.objects[5].u.sphere = (sphere_t){
        .radius = 1e5, 
        .center = (vec3_t) { .x = 50, .y = -1e5+81.6, .z = 81.6 }
    };
    s.objects[5].material.color = (color_t) { .x = 0.75, .y = 0.75, .z = 0.75 };

    s.objects[6].u.sphere = (sphere_t){
        .radius = 20,
        .center = (vec3_t) { .x = 65, .y = 20, .z = 20 }
    };
    s.objects[6].material.color = (color_t) { .x = 0.25, .y = 0.75, .z = 0.25 };
    
    s.objects[7].u.sphere = (sphere_t){
        .radius = 15,
        .center = (vec3_t) { .x = 50, .y = 90, .z = 81.6 }
    };
    s.objects[7].material.emission = (color_t) { .x = 36, .y = 36, .z = 36 };

    return s;
}

void scene_malloc_objects(scene_t * scene, size_t n)
{
    scene->objects_n = n;
    scene->objects = malloc(sizeof(object_t) * n);
}

void scene_free_objects(scene_t * scene)
{
    free(scene->objects);
}

bool scene_intersect(scene_t scene, ray_t ray, intersection_t * out)
{
    out->hit.distance = INF;
    out->object_id = -1;

    for (int i = 0; i < (int)scene.objects_n; i++)
    {
        ray_hit_t hit;
        if (object_intersect(scene.objects + i, ray, &hit))
        {
            if (hit.distance < out->hit.distance)
            {
                out->hit = hit;
                out->object_id = i;
            }
        }
    }
    return out->object_id != -1;
}

object_t * scene_find_object(scene_t scene, unsigned int id)
{
    return scene.objects + id;
}
