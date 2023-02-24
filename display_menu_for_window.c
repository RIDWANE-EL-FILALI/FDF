#include "fdf.h"

void display_menu_for_window(t_dot param)
{
    char *menu;
    menu = "up, down, left, right: move picture";
    mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 5, 0x03fc35, menu);
    menu = "5, space: 3d/2d mode; +, -: zoom";
    mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 20, 0x03fc35, menu);
    menu = "8, 2: z-scale; 4, 6: rotation";
    mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 35, 0x03fc35, menu);
    menu = "f: full screan mode";
    mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 20, 0x03fc35, menu);
}