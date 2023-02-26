#include "fdf.h"

void	new_window(t_dot **matrix)
{
	mlx_clear_window(PRM.mlx_ptr, PRM.win_ptr);
	mlx_destroy_window(PRM.mlx_ptr, PRM.win_ptr);
	PRM.mlx_ptr = mlx_init();
	PRM.win_ptr = mlx_new_window(PRM.mlx_ptr, PRM.win_x, PRM.win_y, "FDF");
	PRM.image_ptr = mlx_new_image(PRM.mlx_ptr, PRM.win_x, PRM.win_y);
	PRM.adrr = mlx_get_data_addr(PRM.image_ptr, &PRM.pixel_per_bit, &PRM.line_size, &PRM.endian);
	PRM.shift_x = PRM.win_x / 3;
	PRM.shift_y = PRM.win_y / 3;
	draw(matrix);
	mlx_clear_window(PRM.mlx_ptr, PRM.win_ptr);
	mlx_key_hook(PRM.win_ptr, deal_key, matrix);
	mlx_loop(PRM.mlx_ptr);
}