/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:27:37 by subpark           #+#    #+#             */
/*   Updated: 2023/08/09 18:11:43 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	modify_x_min(float	***map)
{
	int		i;
	int		index;
	float	distance;

	index = find_min_x(*map);
	distance = (*map)[index][0];
	i = 0;
	while ((*map)[i] != NULL)
	{
		(*map)[i][0] = (*map)[i][0] - distance;
		i ++;
	}
}

void	modify_y_min(float	***map)
{
	int		i;
	int		index;
	float	distance;

	index = find_min_y(*map);
	distance = (*map)[index][1];
	i = 0;
	while ((*map)[i] != NULL)
	{
		(*map)[i][1] = (*map)[i][1] - distance;
		i ++;
	}
}

float	modify_distance(float	**map)
{
	float	size;
	int		max_x;
	int		max_y;
	int		i;

	max_x = find_max_x(map);
	max_y = find_max_y(map);
	size = 0.1;
	i = 0;
	while (map[max_x][0] * size < IMG_WIDTH - 100 && map[max_y][1]
		* size < IMG_HEIGHT - 100)
		size = size * 1.5;
	return (size / 1.5);
}
