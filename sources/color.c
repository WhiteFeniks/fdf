/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:51:59 by umoff             #+#    #+#             */
/*   Updated: 2020/01/31 17:13:05 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

/*
** Функция раскрашивает в зависиомсти от высоты (z) линии 
*/

int	get_default_color(int z, t_map *map)
{
	double	percentage;

	percentage = percent(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (COLOR_LILAC);
	else if (percentage < 0.4)
		return (COLOR_BLUESKY);
	else if (percentage < 0.6)
		return (COLOR_LIME);
	else if (percentage < 0.8)
		return (COLOR_GOLD);
	else
		return (COLOR_RASPBERRIES);
}

/*
** Вспомогательная функция (получения света) 
** для получения линейного градиента
*/

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

/*
** Функция раскрашивает в зависимости от положения точки
** Она необходима для плавного перехода цветов на линии (линейный градиент)
*/

int	get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF,
					percentage);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF,
					percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
