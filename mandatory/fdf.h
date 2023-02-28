#ifndef FDF_H
# define FDF_H

# include "./../get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <mlx.h>
# define PRM matrix[0][0]
# define BUFFER_SIZE 1000

typedef struct
{
	float		x;
	float		y;
	float		z;
	int			is_last;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;

	char *adrr;
	void *image_ptr;
	int endian;
	int pixel_per_bit;
	int line_size;
}				t_dot;


void	isometric(t_dot *dot, double angle);
void	scale_things(t_dot *a, t_dot *b, t_dot *param);
void	set_param(t_dot *a, t_dot *b, t_dot *param);
void	msg_error(char *err);
void	set_default(t_dot *param, char **av);
int check(char *str);
void	draw_map(t_dot **matrix);
void	line(t_dot a, t_dot b, t_dot *param);
void	my_mlx_put_pixel(t_dot *data, int x, int y, int  color);
float MAX(float x, float y);
float	fmodule(float i);
int	get_width(char *str, char c);
int		fill_matrix(char *line, t_dot **matrix_of_dots, int y);
t_dot	**alloc_mem(char *file_name);
t_dot	**read_map(char *file_name);
int		is_key(int key);
void	do_key(int key, t_dot **matrix);
int		deal_key(int key, t_dot **matrix);
int	ft_atoi(const char *str);
char	**ft_split(char *str, char c);
void	print_menu(t_dot param);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
char *ft_line(char *str);
char *ft_next_str(char *str);
char *ft_read(int fd, char *str);
char *get_next_line(int fd);

#endif