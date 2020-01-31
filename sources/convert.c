/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atfoster <atfoster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:52:29 by umoff             #+#    #+#             */
/*   Updated: 2020/01/31 14:57:58 by atfoster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" для структур t_coord_val, t_map; terminate() и pop()
** "libft.h" для ssize_t type ("libft.h" содержит <string.h>),
** size_t ("libft.h" содержит <string.h>) и ft_memalloc()
** "error_message.h" для ERR_CONV_TO_ARR macros
** <stdlib.h> для free()
*/

#include "fdf.h"
#include "libft.h"
#include "error_message.h"
#include <stdlib.h>

/*
** Преобразование стека с элементами структуры t_coord_val 
** (содержит значение z и значение цвета) в массив со значениями z 
** и массив цветовых значений.
*/

void		stack_to_arrays(t_coord_val **coords_stack, t_map *map)
{
	t_coord_val	*coord;
	ssize_t		i;
	size_t		arr_size;

	arr_size = map->width * map->height * sizeof(int);
	if (!(map->coords_arr = (int *)ft_memalloc(arr_size)))
		terminate(ERR_CONV_TO_ARR);
	if (!(map->colors_arr = (int *)ft_memalloc(arr_size)))
		terminate(ERR_CONV_TO_ARR);
	i = map->width * map->height - 1;
	while ((coord = pop(coords_stack)) && i >= 0)
	{
		map->coords_arr[i] = coord->z;
		map->colors_arr[i] = coord->color;
		if (coord->z > map->z_max)
			map->z_max = coord->z;
		if (coord->z < map->z_min)
			map->z_min = coord->z;
		i--;
		free(coord);
	}
	map->z_range = map->z_max - map->z_min;
}
