#include <math.h>
#include "object.h"
#include "math_utils.h"


bool sphere_intersect(const sphere_t * sphere, ray_t ray, ray_hit_t * hit)
{
	vec3_t p_o = vec3_subtract(sphere->center, ray.origin);
	double b = vec3_dot(p_o, ray.dir);
    double d4 = b * b - vec3_dot(p_o, p_o) + sphere->radius * sphere->radius;

	if (d4 < 0.0)
		return false;
		
    double sqrt_d4 = sqrt(d4);
	double t1 = b - sqrt_d4, t2 = b + sqrt_d4;
	
	if (t1 < EPS && t2 < EPS)
		return false;

    hit->distance = t1 > EPS ? t1 : t2; 

	(hit->point) = vec3_add(ray.origin, vec3_multiple(ray.dir, hit->distance));
    hit->normal = vec3_normalize(vec3_subtract(hit->point, sphere->center));
	return true;
}

bool object_intersect(const object_t * object, ray_t ray, ray_hit_t * hit)
{
    switch(object->type)
    {
        case OBJECT_TYPE_SPHERE: return sphere_intersect(&object->u.sphere, ray, hit);
        default: return false;
    }
}
