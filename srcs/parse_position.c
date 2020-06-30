/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/24 18:34:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_secure(t_map *map)
{
	if (map->position_x != 0 || map->position_y != 0 ||
	map->position_direction != '0')
	{
		put_color("\033[31m",
		"\nError\n The beginning position is filled twice !");
		exit(0);
	}
}

void	ft_position_n(t_map *map, int x, int y)
{
	ft_secure(map);
	map->position_x = x;
	map->position_y = y;
	if (map->mapp[x][y] == 'N')
		map->position_direction = 'N';
	ft_check_borders(map, x, y);
}

void	ft_position_s(t_map *map, int x, int y)
{
	ft_secure(map);
	map->position_x = x;
	map->position_y = y;
	if (map->mapp[x][y] == 'S')
		map->position_direction = 'S';
	ft_check_borders(map, x, y);
}

void	ft_position_w(t_map *map, int x, int y)
{
	ft_secure(map);
	map->position_x = x;
	map->position_y = y;
	if (map->mapp[x][y] == 'W')
		map->position_direction = 'W';
	ft_check_borders(map, x, y);
}

void	ft_position_e(t_map *map, int x, int y)
{
	ft_secure(map);
	map->position_x = x;
	map->position_y = y;
	if (map->mapp[x][y] == 'E')
		map->position_direction = 'E';
	ft_check_borders(map, x, y);
}
