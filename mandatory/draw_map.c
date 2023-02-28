#include "fdf.h"

float	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

float MAX(float x, float y)
{
    if (x >= y)
        return (x);
    return (y);
}


void	my_mlx_put_pixel(t_dot *data, int x, int y, int  color)
{
	char	*dst;

	if ((x > 0 && x < 2000) && (y > 0 && y < 2000))
	{
		dst = data->adrr + (y * data->line_size + x * (data->pixel_per_bit / 8));
		*(unsigned int *)dst = color;
	}
}

void	line(t_dot a, t_dot b, t_dot *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = MAX(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	color = (b.z || a.z) ? 0xfc0345 : 0xBBFAFF;
	color = (b.z != a.z) ? 0xfc031c : color;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		my_mlx_put_pixel(param, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}


void	draw_map(t_dot **matrix)
{
	int		y;
	int		x;
	print_menu(PRM);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], &PRM);
			if (matrix[y][x].is_last != 1)
				line(matrix[y][x], matrix[y][x + 1], &PRM);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(PRM.mlx_ptr, PRM.win_ptr, PRM.image_ptr ,400, 0);
}
