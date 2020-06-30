/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/25 21:50:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void					check_pos(t_map *map)
{
	if (map->position_x == 0 && map->position_y == 0)
	{
		put_color("\033[31m", "\nError\n put a beginning position !");
		exit(0);
	}
}

t_map					full_check(t_map map, int i, int j)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y <= i)
	{
		while (map.mapp[y][x] != '\0')
		{
			if ((ft_strcmp_c("012NSWE", map.mapp[y][x]) == 0 &&
			ft_isspace(map.mapp[y][x]) == 0) && map.mapp[y][x] != 0)
			{
				put_color(RED,
				"\nError\n There is a wrong character in your map");
				exit(0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	map = ft_check_map(&map, i, j);
	return (map);
}

void					ft_check_borders(t_map *map, int x, int y)
{
	if (check_above(map, x, y) == 0)
	{
		put_color("\033[31m", "\nError\n wall missing above or wrong element");
		exit(0);
	}
	if (check_below(map, x, y) == 0)
	{
		put_color("\033[31m", "\nError\n wall missing below or wrong element");
		exit(0);
	}
	if (check_left(map, x, y) == 0)
	{
		put_color("\033[31m", "\nError\nwall missing left or wrong element");
		exit(0);
	}
	if (check_right(map, x, y) == 0)
	{
		put_color("\033[31m", "\nError\nwall missing right or wrong element");
		exit(0);
	}
}
