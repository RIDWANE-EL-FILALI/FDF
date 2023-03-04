/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fila <rel-fila@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:03:05 by rel-fila          #+#    #+#             */
/*   Updated: 2023/03/01 15:18:59 by rel-fila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse(t_dot **param)
{
	mlx_destroy_window(param[0][0].mlx_ptr, param[0][0].win_ptr);
	exit(0);
}

int	check(char *str)
{
	int		fd;
	char	*line;
	int		width;
	int		height;

	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	width = 0;
	width = get_width(line, ' ');
	height = 0;
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
		param->scale = 10;
	else if (check(av[1]) == 1)
		param->scale = 20;
	else
		param->scale = 40;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	if (!param->mlx_ptr)
		msg_error("mlx failed !!!");
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->win_x, \
	param->win_y, "FDF");
	if (!param->win_ptr)
		msg_error("mlx failed!!!");
	param->image_ptr = mlx_new_image(param->mlx_ptr, 2000, 2000);
	if (!param->image_ptr)
		msg_error("mlx failed!!!");
	param->adrr = mlx_get_data_addr(param->image_ptr, \
	&param->pixel_per_bit, &param->line_size, &param->endian);
}

int	main(int ac, char **av)
{
	t_dot	**matrix;

	if (ac == 2)
	{
		if (ft_strnstr(av[1], ".fdf", ft_strlen(av[1])) == NULL)
			msg_error("The map you just entered does \
		not end with a .fdf, be careful.");
		matrix = read_map(av[1]);
		set_default(&matrix[0][0], av);
		draw_map(matrix);
		mlx_key_hook(matrix[0][0].win_ptr, deal_key, matrix);
		mlx_hook(matrix[0][0].win_ptr, 17, 0, mouse, matrix);
		mlx_loop(matrix[0][0].mlx_ptr);
	}
	else
		msg_error("usage: ./fdf map.fdf");
	return (0);
}
