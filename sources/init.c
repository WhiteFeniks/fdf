/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atfoster <atfoster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:52:44 by umoff             #+#    #+#             */
/*   Updated: 2020/01/31 14:54:58 by atfoster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" содержит:
** структуры: t_map, t_fdf, t_camera;
** функции: terminate();
** макросы: WIDTH, HEIGHT, INSTRUCTION_WIDTH.
** "libft.h" содержит:
** функции: ft_memalloc();
** макросы: NULL в <string.h>, FT_INT_MAX, FT_INT_MIN, FT_MIN.
** "mlx.h" содержит:
** функции: mlx_init(), mlx_new_window(), mlx_new_image(), mlx_get_data_addr().
** "error_message.h" содержит: 
** макросы: ERR_MAP_INIT, ERR_FDF_INIT, ERR_CAMERA_INIT
*/

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "error_message.h"

/*
** Инициализация структуры t_map
*/

t_map		*map_init(void)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		terminate(ERR_MAP_INIT);
	map->width = 0;
	map->height = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = FT_INT_MAX;
	map->z_max = FT_INT_MIN;
	map->z_range = 0;
	return (map);
}

/*
** Инициализация структуры t_fdf
*/

t_fdf		*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		terminate(ERR_FDF_INIT);
	if (!(fdf->mlx = mlx_init()))
		terminate(ERR_FDF_INIT);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF")))
		terminate(ERR_FDF_INIT);
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		terminate(ERR_FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
										&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	if (!(fdf->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse))))
		terminate(ERR_FDF_INIT);
	return (fdf);
}

/*
** Инициализация структуры t_camera
*/

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		terminate(ERR_CAMERA_INIT);
	camera->zoom = FT_MIN((WIDTH - INSTRUCTION_WIDTH) / fdf->map->width / 2,
												HEIGHT / fdf->map->height / 2);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}
