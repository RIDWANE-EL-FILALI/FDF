/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fila <rel-fila@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:02:55 by rel-fila          #+#    #+#             */
/*   Updated: 2023/03/01 15:18:10 by rel-fila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_key(int key)
{
	return (key == 69 || key == 78 || key == 91 || key == 84 \
	|| key == 126 || key == 125 || key == 123 || key == 124 \
	|| key == 87 || key == 86 || key == 88);
}

void	clear(t_dot **matrix)
{
	mlx_destroy_image(matrix[0][0].mlx_ptr, matrix[0][0].image_ptr);
	mlx_clear_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
	matrix[0][0].image_ptr = mlx_new_image(matrix[0][0].mlx_ptr, 2000, 2000);
	if (!matrix[0][0].image_ptr)
		msg_error("mlx failed in key hook.c");
	matrix[0][0].adrr = mlx_get_data_addr(matrix[0][0].image_ptr, \
	&matrix[0][0].pixel_per_bit, \
	&matrix[0][0].line_size, &matrix[0][0].endian);
}

void	do_key(int key, t_dot **matrix)
{
	if (key == 69)
		matrix[0][0].scale += 3;
	if (key == 78)
		matrix[0][0].scale -= 3;
	if (key == 91)
		matrix[0][0].z_scale += 1;
	if (key == 84)
		matrix[0][0].z_scale -= 1;
	if (key == 126)
		matrix[0][0].shift_y -= 40;
	if (key == 125)
		matrix[0][0].shift_y += 40;
	if (key == 123)
		matrix[0][0].shift_x -= 40;
	if (key == 124)
		matrix[0][0].shift_x += 40;
	if (key == 87)
		check_iso(matrix);
	if (key == 86)
		matrix[0][0].angle += 0.05;
	if (key == 88)
		matrix[0][0].angle -= 0.05;
}

int	deal_key(int key, t_dot **matrix)
{
	if (is_key(key))
	{
		do_key(key, matrix);
		clear(matrix);
		draw_map(matrix);
	}
	if (key == 53)
	{
		mlx_destroy_image(matrix[0][0].mlx_ptr, matrix[0][0].image_ptr);
		mlx_clear_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
		mlx_destroy_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
		free(matrix);
		exit(0);
	}
	return (0);
}

void	check_iso(t_dot **matrix)
{
	if (matrix[0][0].is_isometric)
		matrix[0][0].is_isometric = 0;
	else
		matrix[0][0].is_isometric = 1;
}
