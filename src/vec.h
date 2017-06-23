#ifndef Z_RAY_61edb8075c2f45dfaf8022db348b8cbb
#define Z_RAY_61edb8075c2f45dfaf8022db348b8cbb

typedef struct vec3
{
    double x, y, z;
} vec3_t;

extern const vec3_t VEC3_RIGHT, VEC3_LEFT, VEC3_UP, VEC3_DOWN;

vec3_t vec3_add(const vec3_t lhs, const vec3_t rhs);
vec3_t vec3_subtract(const vec3_t lhs, const vec3_t rhs);
vec3_t vec3_multiple(const vec3_t v, const double rhs);
vec3_t vec3_devide(const vec3_t v, const double rhs);

double vec3_dot(vec3_t v1, vec3_t v2);
vec3_t vec3_cross(vec3_t v1, vec3_t v2);

vec3_t vec3_normalize(const vec3_t v);

double vec3_length_squared(const vec3_t v);
double vec3_length(const vec3_t v);

#endif
