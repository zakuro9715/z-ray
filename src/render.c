#include "render.h"

image_t render(camera_t camera, size_t width, size_t height, size_t samples, size_t supersamples)
{
    image_t image = image_new(width, height);
    for (size_t i = 0; i < image_size(image); i++)
    {
        image.pixels[i] = (color_t) { .x = 0, .y = 0, .z = 0 };
    }
    return image;
}
