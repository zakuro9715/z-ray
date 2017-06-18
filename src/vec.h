#ifndef Z_RAY_61edb8075c2f45dfaf8022db348b8cbb
#define Z_RAY_61edb8075c2f45dfaf8022db348b8cbb

typedef struct vec3
{
    double x, y, z;
} vec3_t;

double vec3_length_squared(vec3_t v);
double vec3_length(vec3_t v);

#endif
