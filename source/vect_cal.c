/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_cal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:56:20 by subpark           #+#    #+#             */
/*   Updated: 2023/08/21 15:25:52 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_angle(float a, float b, float c, float (*angle)[3][3])
{
	(*angle)[0][0] = cos(a) * cos(b);
	(*angle)[0][1] = cos(a) * sin(b) * sin(c) - sin(a) * cos(c);
	(*angle)[0][2] = cos(a) * sin(b) * cos(c) + sin(a) * sin(c);
	(*angle)[1][0] = sin(a) * cos(b);
	(*angle)[1][1] = sin(a) * sin(b) * sin(c) + cos(a) * cos(c);
	(*angle)[1][2] = sin(a) * sin(b) * cos(c) - cos(a) * sin(c);
	(*angle)[2][0] = -sin(b);
	(*angle)[2][1] = cos(b) * sin(c);
	(*angle)[2][2] = cos(b) * cos(c);
}

void	rotate(float ***array)
{
	float	tmp[3];
	float	angle[3][3];
	int		i;
	int		j;

	make_angle(-2, -3.14, 1, &angle);
	i = 0;
	while ((*array)[i] != NULL)
	{
		j = 0;
		while (j < 2)
		{
			tmp[j] = ((*array)[i][0]) * angle[0][j]
				+ ((*array)[i][1]) * angle[1][j]
				+ ((*array)[i][2]) * angle[2][j];
			j ++;
		}
		(*array)[i][0] = tmp[0];
		(*array)[i][1] = tmp[1];
		i ++;
	}
}

void	make_distanced(float ***array, int x, int y)
{
	int		row;
	int		i;
	float	size;

	row = count_rows((void **)*array);
	rotate(array);
	project(array);
	i = 0;
	modify_x_min(array);
	modify_y_min(array);
	size = modify_distance(*array);
	while (i < row)
	{
		(*array)[i][0] = (*array)[i][0] * size + 50 + x;
		(*array)[i][1] = (*array)[i][1] * size + 50 + y;
		i ++;
	}
}

void	pro_vect(float (*project)[3][3])
{
	(*project)[0][0] = 1;
	(*project)[0][1] = 0;
	(*project)[0][2] = 0;
	(*project)[1][0] = 0;
	(*project)[1][1] = 1;
	(*project)[1][2] = 0;
	(*project)[2][0] = 0;
	(*project)[2][1] = 0;
	(*project)[2][2] = 0;
}

void	project(float ***array)
{
	float	project[3][3];
	float	tmp[2];
	int		i;
	int		j;

	pro_vect(&project);
	i = 0;
	while ((*array)[i] != NULL)
	{
		j = 0;
		while (j < 2)
		{
			tmp[j] = ((*array)[i][0]) * project[0][j]
				+ ((*array)[i][1]) * project[1][j]
				+ ((*array)[i][2]) * project[2][j];
			j ++;
		}
		(*array)[i][0] = tmp[0];
		(*array)[i][1] = tmp[1];
		i ++;
	}
}
/*
float	**project(float   **array)
{
	float   project[3][3];
	float	tmp[3];
	float	**newarr;
	int		i;
	int		j;

	pro_vect(&project);
	newarr = ft_calloc(sizeof(float *), count_rows((void **)array) + 1);
	i = 0;
	while (array[i] != NULL)
	{
		j = 0;
		newarr[i] = ft_calloc(sizeof(float), 2);
		while (j < 2)
		{
			tmp[j] = (array[i][0]) * project[0][j]
					+ (array[i][1]) * project[1][j]
					+ (array[i][2]) * project[2][j];
			newarr[i][j] = tmp[j];
			//printf("%f ", newarr[i][j]);
			j ++;
		}
		//printf("\n");
		free(array[i]);
		i ++;
	}
	newarr[i] = NULL;
	free(array);
	make_distanced(&newarr);
	return (newarr);
}
*/
/*
int	main()
{
	char	***tmp;
	char	**arr;
	float	**array;
	float	**final;
	int		i;
	int		j;

	tmp = load_map2(load_map1("42.fdf"));
	//printf("%s", tmp[10][10]);
	array = put_data(alloc_array(tmp), tmp);
	rotate(&array);
	final = project(array);
	i = 0;
	j = 0;
	while (final[i] != NULL)
	{
		j = 0;
		while (j < 2)
		{
			printf("%f, ", final[i][j]);
			j ++;
		}
		free(final[i]);
		printf("\n");
		i ++;
	}
	free(final);
	return (0);
}*/