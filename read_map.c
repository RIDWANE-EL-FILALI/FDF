#include "fdf.h"
/*11111*/
int	get_width(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !(str[i] == c))
			i++;
	}
	return (count);
}
/*222222*/
t_dot **alloc_mem(char *file)
{
    t_dot **new;
    int x;
    int y;
    int fd;
    char *line;

    if ((fd = open(file, O_RDONLY)) <= 0)
    {
        printf("the file you just entered doesn't really exist\n");
        exit(1);
    }
    line = get_next_line(fd);
    x = get_width(line, ' ');
    y = 0;
    while (line)
    {
        free(line);
        line = get_next_line(fd);
        y++;
    }
    free(line);
    new = (t_dot **)malloc(sizeof(t_dot) * (x + 1));
    while (y > 0)
        new[y--] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
    close(fd);
    return (new);
}
/*33333*/
t_dot **read_map(char *file)
{
    t_dot **matrix;
    int y;
    int fd;
    char *line;

    matrix = alloc_mem(file);
    fd = open(file, O_RDONLY);
    y = 0;
    line = get_next_line(fd);
    while (line)
    {
        fill_matrix(line, matrix, y++);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    matrix[y] = NULL;
    close(fd);
    return (matrix);
}
/*444444*/
int fill_matrix(char *line, t_dot **matrix, int y)
{
    char **point;
    int x;

    point = ft_split(line, ' ');
    x = 0;
    while (point[x])
    {
        matrix[y][x].z = ft_atoi(point[x]);
        matrix[y][x].x = x;
        matrix[y][x].y = y;
        matrix[y][x].is_last = 0;
        free(point[x++]);
    }
    free(point);
    free(line);
    matrix[y][--x].is_last = 1;
    return (x);
}