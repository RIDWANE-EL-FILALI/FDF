#include "fdf.h"

void isometric(t_dot *point, double angle)
{
    point->x = (point->x - point->y) * cos(angle);
    point->y = (point->x + point->y) * sin(angle) - point->z;
}