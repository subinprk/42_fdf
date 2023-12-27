/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:14:53 by subpark           #+#    #+#             */
/*   Updated: 2023/08/21 15:26:50 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	find_min_x(float **map)
{
	int		i;
	int		index;
	float	tmp;

	i = 0;
	tmp = map[0][0];
	index = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] < tmp)
		{
			tmp = map[i][0];
			index = i;
		}
		i ++;
	}
	return (index);
}

int	find_min_y(float **map)
{
	int		i;
	int		index;
	float	tmp;

	i = 0;
	tmp = map[0][1];
	index = 0;
	while (map[i] != NULL)
	{
		if (map[i][1] < tmp)
		{
			tmp = map[i][1];
			index = i;
		}
		i ++;
	}
	return (index);
}

int	find_max_x(float **map)
{
	int		i;
	int		index;
	float	tmp;

	i = 0;
	tmp = map[0][0];
	index = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] > tmp)
		{
			tmp = map[i][0];
			index = i;
		}
		i ++;
	}
	return (index);
}

int	find_max_y(float **map)
{
	int		i;
	int		index;
	float	tmp;

	i = 0;
	tmp = map[0][1];
	index = 0;
	while (map[i] != NULL)
	{
		if (map[i][1] > tmp)
		{
			tmp = map[i][1];
			index = i;
		}
		i ++;
	}
	return (index);
}
