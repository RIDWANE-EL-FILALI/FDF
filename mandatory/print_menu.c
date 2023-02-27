#include "fdf.h"

void	print_menu(t_dot param)
{
	char *menu;
	menu = "use just the numeric keypad !!!";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 10, 0x03fc35, menu);
	menu = "up, down, left, right: move picture";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 30, 0x03fc35, menu);
	menu = "5, spase: 3d/2d mode; +, -: zoom";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 50, 0x03fc35, menu);
	menu = "8, 2: z-scale; 4, 6: rotation";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 70, 0x03fc35, menu);
	menu = "f: full screen mode";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 90, 0x03fc35, menu);
}
