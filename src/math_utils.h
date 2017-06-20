#ifndef Z_RAY_f32cfebf8ab4426793909c7d41cde261
#define Z_RAY_f32cfebf8ab4426793909c7d41cde261

extern const double EPS;
extern const double INF;


double int_to_ratio(int value, int max);
int ratio_to_int(double value, int max);
double clamp(double value, double min, double max);

#endif
