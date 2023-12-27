/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 23:18:50 by siun              #+#    #+#             */
/*   Updated: 2023/08/21 15:18:57 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	**total_map(char *path)
{
	char	***tmp;
	float	**array;

	tmp = load_map2(load_map1(path));
	if (!tmp)
		return (NULL);
	array = put_data(alloc_array(tmp), tmp);
	return (array);
}

int	destroy_win(int key, t_vars *vars)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	return (0);
}

int	manage_key_hook(int key, t_vars *vars)
{
	destroy_win(key, vars);
	return (0);
}

int	exit_button(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	float			**map;
	t_vars			vars;
	static t_print	print;
	int				height;

	if (argc != 2)
		return (0);
	map = total_map(argv[1]);
	if (!map || !(*map))
		return (0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, IMG_WIDTH, IMG_HEIGHT, "fdf");
	vars.img = mlx_new_image(vars.mlx, IMG_WIDTH, IMG_HEIGHT);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,
			&vars.line_length, &vars.endian);
	make_distanced(&map, print.x, print.y);
	height = max_z(map);
	print_out(map, vars, argv[1]);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook(vars.win, 2, 1, &manage_key_hook, &vars);
	mlx_hook(vars.win, 17, 0, &exit_button, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
