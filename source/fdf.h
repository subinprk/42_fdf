/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:20:21 by subpark           #+#    #+#             */
/*   Updated: 2023/08/21 15:26:44 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
#  define IMG_WIDTH 1500
#  define IMG_HEIGHT 1000
# endif

# include "../libft/libft.h"
# include <X11/keysym.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
//# include <stdio.h>
/*
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;*/

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_vars;

typedef struct s_print
{
	int	x;
	int	y;
	int	size;
}				t_print;

char	*get_next_line(int fd);
int		merging(char *buff, char **str, int start, int index);
int		count_lines(int fd);
char	**load_map1(const char *path);
int		count_rows(void **map);
char	***load_map2(char **map1);
float	**alloc_array(char ***map);
float	**put_data(float **array, char	***map);
void	make_angle(float a, float b, float c, float (*angle)[3][3]);
void	rotate(float ***array);
void	pro_vect(float (*project)[3][3]);
void	project(float ***array);
void	make_line(t_vars image, float *dot1, float *dot2, int height);
void	print_out(float **map, t_vars image, const char *path);
float	**total_map(char *path);
void	make_distanced(float ***array, int x, int y);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int		max_z(float	**map);
int		find_min_x(float **map);
int		find_min_y(float **map);
int		find_max_x(float **map);
int		find_max_y(float **map);
void	modify_x_min(float	***map);
void	modify_y_min(float	***map);
float	modify_distance(float	**map);

#endif
