#include "fdf.h"

void set_param(t_dot *a, t_dot *b, t_dot *param)
{
    zoom(a, b, param);
    if (param->is_isometric)
    {
        isometric(a, param->angle);
        isometric(b, param->angle);
    }
    a->x += param->shift_x;
    a->y += param->shift_y;
    b->x += param->shift_x;
    b->y += param->shift_y;
}

void zoom(t_dot *a, t_dot *b, t_dot *param)
{
    a->x *= param->scale;
    a->y *= param->scale;
    b->x *= param->scale;
    b->y *= param->scale;
    a->z *= param->z_scale;
    b->z *= param->z_scale;
}