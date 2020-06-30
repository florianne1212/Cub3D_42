/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 22:05:16 by user42            #+#    #+#             */
/*   Updated: 2020/06/18 14:44:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			sprite_cast_1(t_img_coord *co)
{
	t_sprite	sprite;
	int			i;

	i = 0;
	if (!(co->sprite_order = malloc(sizeof(int) * co->mapi.number_sprite)))
		return ;
	if (!(co->spr_dist = malloc(sizeof(double) * co->mapi.number_sprite)))
		return ;
	while (i < co->mapi.number_sprite)
	{
		sprite = co->mapi.sprite[i];
		co->sprite_order[i] = i;
		co->spr_dist[i] = ((co->posx - sprite.x) * (co->posx - sprite.x) +
		(co->posy - sprite.y) * (co->posy - sprite.y));
		i++;
	}
}

void			tri_sprite(t_img_coord *co)
{
	int			i;
	int			j;
	int			t;
	double		p;

	i = 0;
	while (i < (co->mapi.number_sprite))
	{
		j = i + 1;
		while (j < co->mapi.number_sprite)
		{
			if (co->spr_dist[i] < co->spr_dist[j])
			{
				p = co->spr_dist[i];
				co->spr_dist[i] = co->spr_dist[j];
				co->spr_dist[j] = p;
				t = co->sprite_order[i];
				co->sprite_order[i] = co->sprite_order[j];
				co->sprite_order[j] = t;
			}
			j++;
		}
		i++;
	}
	i = 0;
}

void			sprite_cast_2(t_img_coord *co, int i)
{
	co->calc->sprite_x = co->mapi.sprite[co->sprite_order[i]].x -
	co->posx + 0.5;
	co->calc->sprite_y = co->mapi.sprite[co->sprite_order[i]].y -
	co->posy + 0.5;
	co->calc->invdet = 1.0 / (co->planex * co->diry - co->dirx * co->planey);
	co->calc->transformx = co->calc->invdet * (co->diry *
	co->calc->sprite_x - co->dirx * co->calc->sprite_y);
	co->calc->transformy = co->calc->invdet * (-co->planey *
	co->calc->sprite_x + co->planex * co->calc->sprite_y);
	co->calc->scren_x = (int)((co->argi.reso_x / 2) *
	(1 + co->calc->transformx / co->calc->transformy));
}

void			sprite_cast_3(t_img_coord *co)
{
	co->calc->height = abs((int)(co->argi.reso_y / (co->calc->transformy))) / 1;
	co->calc->drawstarty = -co->calc->height / 2 + co->argi.reso_y / 2;
	if (co->calc->drawstarty < 0)
		co->calc->drawstarty = 0;
	co->calc->drawendy = co->calc->height / 2 + co->argi.reso_y / 2;
	if (co->calc->drawendy >= co->argi.reso_y)
		co->calc->drawendy = co->argi.reso_y - 1;
}
