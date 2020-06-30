/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:50:52 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/18 15:22:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_twice_res(t_args *args)
{
	if (args->reso_x != -1 || args->reso_x != -1)
	{
		put_color(RED, "\nError\n resolution is defined twice");
		exit(0);
	}
}

size_t	ft_resolution(char *line, int e, t_args *args)
{
	int i;

	i = 0;
	if (line[e] == 'R' && (ft_isspace(line[e + 1]) == 1 || line[e + 1] == 0))
	{
		i += find_i(line, e, 2);
		check_twice_res(args);
		args->reso_x = ft_atoi_test(&line[e + 1]);
		if (ft_isspace(line[e + 1]) == 0)
		{
			put_color("\033[31m", "\nError\n Missing space or arguments");
			exit(0);
		}
		i += ft_count(args->reso_x) + 1;
		args->reso_y = ft_atoi_test(&line[e + i + 1]);
		if (args->reso_y == -1 || args->reso_x == -1)
		{
			put_color(RED, "\nError\n wrong number of argument for resolution");
			exit(0);
		}
	}
	return (i + ft_count(args->reso_y) + 1);
}

t_args	check_resolution(t_args argy, t_mlx_coord mlxco)
{
	mlxco.size_x = malloc(sizeof(int*));
	mlxco.size_y = malloc(sizeof(int*));
	mlx_get_screen_size(mlxco.mlx, mlxco.size_x, mlxco.size_y);
	if (argy.save == 0)
	{
		if (argy.reso_x >= *mlxco.size_x)
		{
			argy.reso_x = *mlxco.size_x;
			put_color("\033[33m", "\nError\n resolution x has been resized");
		}
		if (argy.reso_y >= *mlxco.size_y)
		{
			argy.reso_y = *mlxco.size_y;
			put_color("\033[33m", "\nError\n resolution y has been resized");
		}
	}
	free(mlxco.size_x);
	free(mlxco.size_y);
	return (argy);
}
