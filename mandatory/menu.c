/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fila <rel-fila@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:03:14 by rel-fila          #+#    #+#             */
/*   Updated: 2023/03/01 12:03:16 by rel-fila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_dot param)
{
	char	*menu;

	menu = "use just the numeric keypad !!!";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 10, 0x03fc35, menu);
	menu = "up, down, left, right: move picture";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 30, 0x03fc35, menu);
	menu = "5: 3d/2d mode; +, -: zoom";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 50, 0x03fc35, menu);
	menu = "8, 2: z-scale; 4, 6: rotation";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 70, 0x03fc35, menu);
}
