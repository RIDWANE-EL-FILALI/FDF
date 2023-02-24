# ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <mlx.h>
#include "./../get_next_line/get_next_line.h"

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
}				t_dot;


int check_win_size(int key, t_dot **matrix);
void full_screen(t_dot **matrix);
void change_window_size(int key, t_dot **matrix);
void new_window(int key, t_dot **matrix);
int is_key(int key);
void do_key(int key, t_dot **matrix);
int deal_key(int key, t_dot **matrix);
void display_menu_for_window(t_dot param);
void draw_map(t_dot **matrix);
void line(t_dot a, t_dot b, t_dot *param);
int	ft_atoi(const char *str);
char	**ft_split(char *str, char c);
void set_default(t_dot *param);
void isometric(t_dot *point, double angle);
int	get_width(char *str, char c);
t_dot **alloc_mem(char *file);
t_dot **read_map(char *file);
int fill_matrix(char *line, t_dot **matrix, int y);
void set_param(t_dot *a, t_dot *b, t_dot *param);
void zoom(t_dot *a, t_dot *b, t_dot *param);
float	fmodule(float i);


#endif