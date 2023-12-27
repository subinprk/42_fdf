/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:28:33 by subpark           #+#    #+#             */
/*   Updated: 2023/07/24 14:36:22 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

struct s_buf
{
	char	buff[BUFFER_SIZE];
	int		index;
	int		tmp;
};

int	initialise_buf(struct s_buf *buf, char **str)
{
	buf->index = 0;
	buf->tmp = 0;
	buf->buff[0] = '\0';
	free(*str);
	return (1);
}

void	read_new(struct s_buf *buf, int fd)
{
	ft_bzero(buf->buff, buf->tmp);
	buf->tmp = read(fd, buf->buff, BUFFER_SIZE);
	buf->index = 0;
}

int	narrow(struct s_buf *buf, char **str, int start)
{
	buf->index ++;
	merging(buf->buff, str, start, buf->index);
	return (1);
}

int	merging(char *buff, char **str, int start, int index)
{
	char	*tmp;

	tmp = NULL;
	if (start == index)
		return (1);
	else if (*str)
	{
		tmp = ft_strdup(*str);
		free(*str);
		*str = (char *)ft_calloc(ft_strlen(tmp) + index - start + 1,
				sizeof(char));
		(*str)[0] = '\0';
		ft_strlcat(*str, tmp, ft_strlen(tmp) + 1);
		ft_strlcat(*str, buff + start, ft_strlen(tmp) + index - start + 1);
		free(tmp);
	}
	else
	{
		*str = (char *)ft_calloc(index - start + 1, sizeof(char));
		if (!(*str))
			return (0);
		(*str)[0] = '\0';
		ft_strlcat(*str, buff + start, index - start + 1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static struct s_buf	b;
	char				*str;
	int					start;

	str = NULL;
	if (b.buff[0] == '\0')
		b.tmp = read(fd, b.buff, BUFFER_SIZE);
	while (b.tmp > 0)
	{
		start = b.index;
		while (b.index < b.tmp && b.buff[b.index] != 10 && b.buff[b.index] != 0)
			b.index ++;
		if (b.buff[b.index] == 10 && b.index < b.tmp && narrow(&b, &str, start))
			break ;
		merging(b.buff, &str, start, b.index);
		if (b.index == b.tmp)
			read_new(&b, fd);
		else
			break ;
	}
	if (b.tmp < 0 && initialise_buf(&b, &str))
		return (NULL);
	return (str);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main()
{
	const char	*filename = "41_with_nl";
	//char	*str;
	int fd = open(filename, O_RDONLY);
	if (fd < 3)
		return 0;

	char *line;

	line = get_next_line(fd);
	while (line) {
		printf("line : %s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return 0;
}*/