/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:50:52 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/18 15:22:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_right(t_map *map, int x, int y)
{
	int	i;
	int	test;

	i = 0;
	test = 0;
	while ((y + i) < map->width_map && (map->mapp[x][y + i] != 32))
	{
		if (ft_strcmp_c("012NSWE", map->mapp[x][y + i]) == 0)
		{
			put_color(RED,
			"\nError\n wrong character in map or too many elements");
			exit(0);
		}
		if (map->mapp[x][y + i] == '1')
			test = 1;
		i++;
	}
	if (test == 1)
		return (1);
	return (0);
}

int		check_left(t_map *map, int x, int y)
{
	int	test;

	test = 0;
	while (y >= 0 && (map->mapp[x][y] != 32))
	{
		if (ft_strcmp_c("012NSWE", map->mapp[x][y]) == 0)
		{
			put_color(RED,
			"\nError\n wrong character in map or too many elements");
			exit(0);
		}
		if (map->mapp[x][y] == '1')
			test = 1;
		y--;
	}
	if (test == 1)
		return (1);
	return (0);
}

int		check_above(t_map *map, int x, int y)
{
	int	i;
	int	test;

	i = 0;
	test = 0;
	while ((x + i) <= map->height_map && (map->mapp[x + i][y] != 32))
	{
		if (ft_strcmp_c("012NSWE", map->mapp[x + i][y]) == 0)
		{
			put_color(RED,
			"\nError\n wrong character in map or too many elements");
			exit(0);
		}
		if (map->mapp[x + i][y] == '1')
			test = 1;
		i++;
	}
	if (test == 1)
		return (1);
	return (0);
}

int		check_below(t_map *map, int x, int y)
{
	int	test;

	test = 0;
	while ((x) >= 0 && (map->mapp[x][y] != 32))
	{
		if (ft_strcmp_c("012NSWE", map->mapp[x][y]) == 0)
		{
			put_color(RED,
			"\nError\n wrong character in map or too many elements");
			exit(0);
		}
		if (map->mapp[x][y] == '1')
			test = 1;
		x--;
	}
	if (test == 1)
		return (1);
	return (0);
}
