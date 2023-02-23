# ifndef FDF_H
#define FDF_H

#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./../get_next_line/get_next_line.h"

typedef struct s_map
{
    void *mlx_ptr;
    void *win_ptr;
    int height;
    int width;
    char *file;
}   t_map;



char	**ft_split(char *str, char c);

#endif