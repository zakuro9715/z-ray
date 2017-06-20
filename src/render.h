#ifndef Z_RAY_85af542441ff4e8c9f6aad9c2f9ecf86
#define Z_RAY_85af542441ff4e8c9f6aad9c2f9ecf86

#include <stddef.h>

#include "camera.h"
#include "image.h"
#include "scene.h"

image_t render(camera_t camera, scene_t scene, size_t width, size_t samples, size_t supersamples);

#endif
