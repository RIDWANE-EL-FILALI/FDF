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


t_dot			**read_map(char *file_name);
void			isometric(t_dot *dot, double angle);
void			draw(t_dot **matrix);
int				deal_key(int key, t_dot **matrix);
void			set_param(t_dot *a, t_dot *b, t_dot *param);
void			print_menu(t_dot param);
void			ft_error(char *msg);
void	new_window(t_dot **matrix);
int	get_width(char *str, char c);
char	**ft_split(char *str, char c);
int	ft_atoi(const char *str);
#endif