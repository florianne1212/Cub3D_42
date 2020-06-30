/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/23 19:53:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map					set_map(t_map *map, int i, int j)
{
	int					e;

	e = 0;
	map->position_y = 0;
	map->position_x = 0;
	map->position_direction = '0';
	map->height_map = i;
	map->width_map = j;
	if (!(map->mapp = (char **)malloc(sizeof(char *) * (i + 1))))
		return (*map);
	while (e <= i)
	{
		map->mapp[e] = ft_strnew(j, 32);
		e++;
	}
	return (*map);
}

void					set_funct_map(t_map_funct *funct_map)
{
	size_t				i;

	i = 0;
	while (i < 254)
	{
		funct_map[i] = NULL;
		i++;
	}
	funct_map[0] = (void *)(-1);
	funct_map['0'] = ft_check_borders;
	funct_map['2'] = ft_sprite;
	funct_map['N'] = ft_position_n;
	funct_map['S'] = ft_position_s;
	funct_map['W'] = ft_position_w;
	funct_map['E'] = ft_position_e;
}

t_map					ft_check_map(t_map *map, int i, int j)
{
	static	t_map_funct	funct_map[255] = {NULL};
	int					x;
	int					y;

	x = 0;
	y = 0;
	if (funct_map[0] == NULL)
		set_funct_map(funct_map);
	map->number_sprite = 0;
	while (x < i + 1)
	{
		while (y < j)
		{
			if (funct_map[(int)map->mapp[x][y]] != NULL)
				funct_map[(int)map->mapp[x][y]](map, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	check_pos(map);
	ft_tab_sprite(map);
	return (*map);
}

int						read_line(int fd, int count)
{
	int					r;
	char				*line;

	while ((r = get_next_line(fd, &line)) == 1 && count > 1)
	{
		free(line);
		count--;
	}
	free(line);
	count = 0;
	return (count);
}

t_map					ft_parse_map(int i, int j, int count, char *path)
{
	t_map				map;
	int					fd;
	char				*line;
	int					r;
	int					e;

	e = 0;
	map = set_map(&map, i, j);
	fd = open(path, O_RDONLY);
	count = read_line(fd, count);
	while ((r = get_next_line(fd, &line) >= 0 && count < i + 1))
	{
		while (line[e] != '\0')
		{
			map.mapp[count][e] = line[e];
			e++;
		}
		e = 0;
		free(line);
		count++;
	}
	free(line);
	close(fd);
	map = full_check(map, i, j);
	return (map);
}
