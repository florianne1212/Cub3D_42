/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 21:20:33 by user42            #+#    #+#             */
/*   Updated: 2020/06/17 18:30:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_position(t_img_coord *co)
{
	double	i;
	double	j;
	int		e;

	i = (co->argi.reso_x / 5) / co->mapi.width_map;
	j = (co->argi.reso_y / 5) / (co->mapi.height_map);
	e = 0;
	if (co->argi.reso_x > 15 && co->argi.reso_y > 15)
	{
		while (e < 5)
		{
			my_mlx_pixel_put(co->img, ((co->posx * i) + e),
			((co->posy * j)), 0x00FF0000);
			my_mlx_pixel_put(co->img, ((co->posx * i) - e),
			((co->posy * j)), 0x00FF0000);
			my_mlx_pixel_put(co->img, (co->posx * i),
			(co->posy * j - e), 0x00FF0000);
			my_mlx_pixel_put(co->img, (co->posx * i),
			(co->posy * j + e), 0x00FF0000);
			e++;
		}
	}
}

int			chose_color(t_img_coord *co, int x, int y)
{
	if (co->mapi.mapp[y][x] == '0' || co->mapi.mapp[y][x] == 'N' ||
	co->mapi.mapp[y][x] == 'S' || co->mapi.mapp[y][x] == 'W' ||
	co->mapi.mapp[y][x] == 'E')
		return (1);
	return (0);
}

void		draw_square(t_img_coord *co, int x, int y)
{
	int		color;
	double	i;
	double	j;
	int		a;
	int		b;

	i = co->argi.reso_x / 5 / co->mapi.width_map;
	j = co->argi.reso_y / 5 / (co->mapi.height_map);
	a = 0;
	while ((x + a) < (x + i))
	{
		b = 0;
		while ((y + b) < (y + j))
		{
			if (co->mapi.mapp[y][x] == '1')
				color = 0x00337C85;
			else if (chose_color(co, x, y) == 1)
				color = 0x00F1D2FB;
			else
				color = 0x00581845;
			my_mlx_pixel_put(co->img, ((x * i) + a), ((y * j) + b), color);
			b++;
		}
		a++;
	}
}

void		draw_minimap(t_img_coord *co)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < co->mapi.width_map)
	{
		while (y <= co->mapi.height_map)
		{
			draw_square(co, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	draw_position(co);
}
