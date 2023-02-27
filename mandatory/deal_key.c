#include "fdf.h"

int		is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 ||\
	key == 91 || key == 28 || key == 84 || key == 19 ||\
	key == '~' || key == '}' || key == '{' || key == '|' ||\
	key == 87 || key == 23 || key == 86 || key == 21 ||\
	key == 49 || key == 88 || key == 22);
}

void clear(t_dot **matrix)
{
	mlx_destroy_image(PRM.mlx_ptr, PRM.image_ptr);
	mlx_clear_window(PRM.mlx_ptr, PRM.win_ptr);
	PRM.image_ptr = mlx_new_image(PRM.mlx_ptr, PRM.win_x, PRM.win_y);
	PRM.adrr = mlx_get_data_addr(PRM.image_ptr, &PRM.pixel_per_bit, &PRM.line_size, &PRM.endian);
}

void	do_key(int key, t_dot **matrix)
{
	if (key == 24 || key == 69)
		PRM.scale += 1;
	if (key == 27 || key == 78)
		PRM.scale -= 1;
	if (key == 91 || key == 28)
		PRM.z_scale += 1;
	if (key == 84 || key == 19)
		PRM.z_scale -= 1;
	if (key == '~')
		PRM.shift_y -= 40;
	if (key == '}')
		PRM.shift_y += 40;
	if (key == '{')
		PRM.shift_x -= 40;
	if (key == '|')
		PRM.shift_x += 40;
	if (key == 49 || key == 87 || key == 23)
		PRM.is_isometric = (PRM.is_isometric) ? 0 : 1;
	if (key == 86 || key == 21)
		PRM.angle += 0.05;
	if (key == 88 || key == 22)
		PRM.angle -= 0.05;

}

int		deal_key(int key, t_dot **matrix)
{
	if (is_key(key))
	{
		do_key(key, matrix);
		clear(matrix);
		print_menu(PRM);
		draw(matrix);
	}
	if (key == 53)
	{
		mlx_destroy_image(PRM.mlx_ptr, PRM.image_ptr);
		mlx_clear_window(PRM.mlx_ptr, PRM.win_ptr);
		mlx_destroy_window(PRM.mlx_ptr, PRM.win_ptr);
		free(matrix);
		exit(0);
	}
	return (0);
}