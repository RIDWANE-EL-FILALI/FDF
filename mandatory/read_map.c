/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fila <rel-fila@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:03:25 by rel-fila          #+#    #+#             */
/*   Updated: 2023/03/01 12:03:27 by rel-fila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0' && str[i] != '\n')
			count++;
		while (str[i] != '\0' && !(str[i] == c))
			i++;
	}
	return (count);
}

int	fill_matrix(char *line, t_dot **matrix_of_dots, int y)
{
	char	**dots;
	int		x;
	int		width;

	width = get_width(line, ' ');
	dots = ft_split(line, ' ');
	x = 0;
	while (x < width)
	{
		matrix_of_dots[y][x].z = ft_atoi(dots[x]);
		matrix_of_dots[y][x].x = x;
		matrix_of_dots[y][x].y = y;
		matrix_of_dots[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	free(line);
	matrix_of_dots[y][--x].is_last = 1;
	return (x);
}

t_dot	**alloc_mem(char *file_name)
{
	t_dot	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd <= 2)
		msg_error("file does not exist");
	line = get_next_line(fd);
	x = get_width(line, ' ');
	y = 1;
	while (line)
	{
		if (ft_isprint(*line))
			y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	new = (t_dot **)malloc(sizeof(t_dot *) * (y--));
	while (y > 0)
		new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x));
	close(fd);
	return (new);
}

t_dot	**read_map(char *file_name)
{
	t_dot	**matrix_of_dots;
	int		y;
	int		fd;
	char	*line;

	matrix_of_dots = alloc_mem(file_name);
	fd = open(file_name, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(line, matrix_of_dots, y++);
		line = get_next_line(fd);
	}
	free(line);
	matrix_of_dots[y] = 0;
	close (fd);
	return (matrix_of_dots);
}
