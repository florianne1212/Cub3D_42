/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:49:29 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/17 14:57:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_sprite(t_map *map, int x, int y)
{
	int		a;
	int		n;

	map->number_sprite++;
	a = x;
	n = y;
}

t_sprite	load_sprites(t_sprite sprite, int x, int y)
{
	sprite.x = y;
	sprite.y = x;
	return (sprite);
}

void		ft_tab_sprite(t_map *map)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	if (!(map->sprite = malloc(sizeof(t_sprite) * map->number_sprite)))
		return ;
	while (x < map->height_map)
	{
		while (y < map->width_map)
		{
			if (map->mapp[x][y] == '2' && i < map->number_sprite)
			{
				map->sprite[i] = load_sprites(map->sprite[i], x, y);
				i++;
			}
			y++;
		}
		y = 0;
		x++;
	}
}
