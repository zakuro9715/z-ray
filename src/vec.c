#include <math.h>
#include "vec.h"

const vec3_t VEC3_RIGHT = {  1,  0,  0 };
const vec3_t VEC3_LEFT  = { -1,  0,  0 };
const vec3_t VEC3_UP    = {  0,  1,  0 };
const vec3_t VEC3_DOWN  = {  0, -1,  0 };


inline
vec3_t vec3_add(const vec3_t lhs, const vec3_t rhs)
{
    return (vec3_t) {
        .x = lhs.x + rhs.x,
        .y = lhs.y + rhs.y,
        .z = lhs.z + rhs.z,
    };
}

inline
vec3_t vec3_subtract(const vec3_t lhs, const vec3_t rhs)
{
    return (vec3_t) {
        .x = lhs.x - rhs.x,
        .y = lhs.y - rhs.y,
        .z = lhs.z - rhs.z,
    };
}

inline
vec3_t vec3_multiple(const vec3_t v, const double rhs)
{
    return (vec3_t) {
        .x = v.x * rhs,
        .y = v.y * rhs,
        .z = v.z * rhs
    };
}

inline
vec3_t vec3_devide(const vec3_t v, const double rhs)
{
    return (vec3_t) {
        .x = v.x / rhs,
        .y = v.y / rhs,
        .z = v.z / rhs
    };
}

inline
double vec3_dot(vec3_t v1, vec3_t v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline
vec3_t vec3_cross(vec3_t v1, vec3_t v2)
{
    return (vec3_t) {
        .x = v1.y * v2.z - v1.z * v2.y,
        .y = v1.z * v2.x - v1.x * v2.z,
        .z = v1.x * v2.y - v1.y * v2.x
    };
}

inline
vec3_t vec3_normalize(const vec3_t v)
{
    return vec3_devide(v, vec3_length(v));
}


inline
double vec3_length_squared(const vec3_t v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

inline
double vec3_length(const vec3_t v)
{
    return sqrt(vec3_length_squared(v));
}
