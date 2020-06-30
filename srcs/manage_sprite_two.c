/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sprite_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 22:05:16 by user42            #+#    #+#             */
/*   Updated: 2020/06/25 19:46:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_cast_4(t_img_coord *co)
{
	co->calc->width = abs((int)(co->argi.reso_y / (co->calc->transformy)));
	co->calc->drawstartx = -co->calc->width / 2 + co->calc->scren_x;
	if (co->calc->drawstartx < 0)
		co->calc->drawstartx = 0;
	co->calc->drawendx = co->calc->width / 2 + co->calc->scren_x;
	if (co->calc->drawendx >= co->argi.reso_x)
		co->calc->drawendx = co->argi.reso_x - 1;
}

int		color_sprite(t_img_coord *co, int texx, int texy)
{
	int color;

	color = (*(int *)(co->text_sp->addr + (4 * texx) +
	(co->text_sp->line_length * texy)));
	return (color);
}

void	draw(t_img_coord *co, int texx, int stripe, int texy)
{
	int y;
	int color;
	int d;
	int movescreen;

	d = 0;
	color = 0;
	movescreen = 0.0 / co->calc->transformy;
	y = co->calc->drawstarty;
	while (y < co->calc->drawendy)
	{
		d = (y - movescreen) * 256 - co->argi.reso_y * 128 +
		co->calc->height * 128;
		texy = ((d * co->text_sp->height) / co->calc->height) / 256;
		if (texy >= 0)
		{
			color = color_sprite(co, texx, texy);
			if ((color & 0X00FFFFFF) != 0)
				my_mlx_pixel_put(co->img, stripe, y, color);
		}
		y++;
	}
}

void	draw_sprite(t_img_coord *co, int i)
{
	int stripe;
	int texx;
	int texy;
	int movescreen;

	texy = 0;
	texy = 0;
	movescreen = 0.0 / co->calc->transformy;
	i = 5;
	stripe = co->calc->drawstartx;
	while (stripe < co->calc->drawendx)
	{
		texx = (int)(256 * (stripe - (-co->calc->width / 2 +
		co->calc->scren_x)) * co->text_sp->width / co->calc->width) / 256;
		if (co->calc->transformy > 0 && stripe > 0 &&
		stripe < co->argi.reso_x &&
		co->calc->transformy < (co->buf_sprit[stripe]))
		{
			draw(co, texx, stripe, texy);
		}
		stripe++;
	}
}

void	sprite_cast(t_img_coord *co)
{
	int i;

	i = 0;
	sprite_cast_1(co);
	tri_sprite(co);
	while (i < co->mapi.number_sprite)
	{
		sprite_cast_2(co, i);
		sprite_cast_3(co);
		sprite_cast_4(co);
		draw_sprite(co, i);
		i++;
	}
	free(co->sprite_order);
	free(co->spr_dist);
}
