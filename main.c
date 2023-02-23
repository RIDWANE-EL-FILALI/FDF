#include "fdf.h"

int get_width_height(t_map map)
{
    char **sab;
    char *tab;

    int width = 0;
    int height = 0;
    int i = 0;
    int fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (1);
    tab = get_next_line(fd);
    map->width = 

}

int initiate_data(char **av, t_map *map)
{
    map->file = av[1];
    if (get_width_height(map) == 1)
        exit(1);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        t_map *map;

        map = (t_map *)malloc(sizeof(t_map));
        initiate_data(av, map);
    }
    return (0);
}