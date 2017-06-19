#include <math.h>
#include "vec.h"

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
