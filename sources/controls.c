/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:52:17 by umoff             #+#    #+#             */
/*   Updated: 2020/01/30 17:47:10 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

/*
** Функция для того, чтобы закрывался проект, когда нажимаешь на красный 
** крестик в верхнем левом углу. Для нее подключена библиотека stdlib.h
*/

int		close(void *param)
{
	(void)param;
	exit(0);
}

/*
** Подключение функций нажатия клавиш, закрытие, нажатие мышки,
** отпускание мышки, движение мышки для окна
*/

void	setup_controls(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->win, 17, 0, close, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 0, mouse_move, fdf);
}
