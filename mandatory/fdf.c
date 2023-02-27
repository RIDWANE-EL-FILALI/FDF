#include "fdf.h"

int check(char *str)
{
	int fd = open(str, O_RDONLY);
	char *line;
	line = get_next_line(fd);
	int width = 0;
	width = get_width(line, ' ');
	int height = 0;
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (width >= 100 || height >= 100)
		return (2);
	else if (width >= 29 || height >= 29)
		return (1);
	else
		return (0);
}

void	set_default(t_dot *param, char **av)
{
	if (check(av[1]) == 2)
		param->scale = 1;
	else if (check(av[1]) == 1)
		param->scale = 10;
	else
		param->scale = 40;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_x = 2850;
	param->win_y = 1400;
	param->shift_x = param->win_x / 4;
	param->shift_y = param->win_y / 4;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
	param->image_ptr = mlx_new_image(param->mlx_ptr, param->win_x, param->win_y);
	param->adrr = mlx_get_data_addr(param->image_ptr, &param->pixel_per_bit, &param->line_size, &param->endian);
}

int		main(int ac, char **av)
{
	t_dot	**matrix;

	if (ac == 2)
	{
		matrix = read_map(av[1]);
		set_default(&PRM, av);
		draw(matrix);
		mlx_key_hook(PRM.win_ptr, deal_key, matrix);
		mlx_loop(PRM.mlx_ptr);
	}
	else
		ft_error("usage: ./fdf map.fdf");
	return(0);
}