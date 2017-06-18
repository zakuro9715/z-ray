#ifndef Z_RAY_61edb8075c2f45dfaf8022db348b8cbb
#define Z_RAY_61edb8075c2f45dfaf8022db348b8cbb

typedef struct vec3
{
    double x, y, z
} vec3;

double vec3_length_squared(vec3 v);
double vec3_length(vec3 v);

#endif
