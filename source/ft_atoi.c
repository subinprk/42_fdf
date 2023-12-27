/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:12:19 by subpark           #+#    #+#             */
/*   Updated: 2023/08/10 17:18:07 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	spc(char c)
{
	if (c == '\t' || c == '\n' || c == ' ' || c == '\r' || c == '\v'
		||c == '\f')
		return (1);
	else
		return (0);
}

void	signs(const char *nptr, int *index, int *sign)
{
	if (nptr[*index] == '-')
		*sign = -1;
	if (nptr[*index] == '+' || nptr[*index] == '-')
		(*index)++;
}

int	base_16(const char *nptr)
{

}

int	ft_16_atoi(const char *nptr)
{
	int	num;
	int	index;
	int	sign;

	sign = 1;
	num = 0;
	index = 0;
	if (nptr[1] == 'x')
		return (base_16(nptr));
	while ((nptr[index] != 0 && spc(nptr[index]) == 1))
		index ++;
	if (!ft_memcmp(&nptr[index], "-2147483648", 11))
		return (-2147483648);
	signs(nptr, &index, &sign);
	while (nptr[index] != 0)
	{
		if (nptr[index] < '0' || nptr[index] > '9')
			return (sign * num);
		else if (10 * num + (nptr[index] - '0') < num)
			return (0);
		else
			num = 10 * num + (nptr[index] - '0');
		index ++;
	}
	return (sign * num);
}
/*
#include <stdio.h>
void main()
{
	printf("%d \n", atoi("  -2147648wrf"));
	printf("%d", ft_atoi("  -2147648wrf"));
}
*/