/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:46:17 by subpark           #+#    #+#             */
/*   Updated: 2023/08/10 16:48:33 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	countrow(char const *s, char c, char d)
{
	char	prvc;
	int		index;
	int		row;

	row = 0;
	index = 0;
	prvc = 0;
	if ((s[index] != c && s[index] != d) && s[index] != 0)
		row ++;
	while (s[index])
	{
		if ((prvc == c || prvc == d) && (s[index] != c && s[index] != d))
			row ++;
		prvc = s[index];
		index ++;
	}
	if (s[index] == 0)
		row = row - 1;
	return (row);
}

int	tool4free(char **str, int i4str)
{
	if (str[i4str] == NULL)
	{
		while (i4str >= 0)
			free(str[i4str --]);
		free(str);
		return (-1);
	}
	return (1);
}

char	**linebyline(char **str, char const *s, char c, char d)
{
	int	index;
	int	i4str;
	int	start;

	index = 0;
	i4str = 0;
	while (s[index])
	{
		if (s[index] != c && s[index] != d)
		{
			start = index;
			while (s[index] != c && s[index] != d)
				index ++;
			str[i4str] = ft_substr(s, start, index - start);
			if (tool4free(str, i4str) < 0)
				return (NULL);
			i4str ++;
		}
		else
			index ++;
	}
	str[i4str] = NULL;
	return (str);
}

char	**ft_2_split(char const *s, char c, char d)
{
	char	**str;
	int		row;

	row = countrow(s, c, d);
	str = (char **)malloc((row + 1) * sizeof(char *));
	if (!str || !s)
		return (NULL);
	str = linebyline(str, s, c, d);
	return (str);
}
