/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:53:08 by umoff             #+#    #+#             */
/*   Updated: 2020/01/31 18:06:10 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "color.h"

/*
** Функция печати инструкции на окне
*/

void	print_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 80, y += 20, TEXT_COLOR, "FDF Instruction");
	mlx_string_put(mlx, win, 20, y += 35, TEXT_COLOR, "Zoom: scroll mouse or +/- keys");
	mlx_string_put(mlx, win, 20, y += 30, TEXT_COLOR, "Move: arrows on the keyboard");
	mlx_string_put(mlx, win, 20, y += 30, TEXT_COLOR, "Stretching: </> keys");
	mlx_string_put(mlx, win, 20, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 62, y += 25, TEXT_COLOR, "Press & Move");
	mlx_string_put(mlx, win, 62, y += 25, TEXT_COLOR, "X-Axis - 2/8 keys");
	mlx_string_put(mlx, win, 62, y += 25, TEXT_COLOR, "Y-Axis - 4/6 keys");
	mlx_string_put(mlx, win, 62, y += 25, TEXT_COLOR, "Z-Axis - 1/7 keys");
	mlx_string_put(mlx, win, 20, y += 30, TEXT_COLOR, "Projection:");
	mlx_string_put(mlx, win, 62, y += 25, TEXT_COLOR, "Isometric view (3D): I key");
	mlx_string_put(mlx, win, 62, y += 25, TEXT_COLOR, "Parallel view (2D): P Key");
}
