/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_textured.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:50:52 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/25 21:59:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img_coord		manage_3d(t_img_coord *co)
{
	while (co->x < co->argi.reso_x)
	{
		init_calc_finder(co, co->argi);
		dir_dist_finder(co);
		dda_calc(co);
		dist_heigh_calc(co);
		start_end_calc(co);
		texture_calc(co);
		draw_3d(co);
		co->buf_sprit[co->x] = co->longueur_mur;
		co->x++;
	}
	sprite_cast(co);
	draw_minimap(co);
	if (co->argi.save == 0)
		mlx_put_image_to_window(co->mlx.mlx, co->mlx.mlx_win,
		co->img->img, 0, 0);
	return (*co);
}

t_img_coord		init_imgco(t_img_coord imgco, t_map mapy)
{
	imgco.mapi = mapy;
	imgco.posx = mapy.position_y;
	imgco.posy = mapy.position_x;
	imgco.camerax = 0;
	imgco.dist_murx = 0;
	imgco.dist_mury = 0;
	imgco.longueur_mur = 0;
	imgco.etapex = 0;
	imgco.etapey = 0;
	imgco.hori_verti = 2;
	imgco.mapx = 0;
	imgco.mapy = 0;
	imgco.x = 0;
	imgco = init_position(imgco);
	imgco = init_color(imgco);
	imgco.count = 0;
	return (imgco);
}

t_img_coord		init_calc_finder(t_img_coord *co, t_args argy)
{
	co->rayposx = co->posx;
	co->rayposy = co->posy;
	co->camerax = 2 * co->x / (double)(argy.reso_x) - 1;
	co->raydirx = co->dirx + co->planex * co->camerax;
	co->raydiry = co->diry + co->planey * co->camerax;
	co->mapx = (int)co->rayposx;
	co->mapy = (int)co->rayposy;
	co->dist2murx = sqrt(1 + (co->raydiry * co->raydiry) /
	(co->raydirx * co->raydirx));
	co->dist2mury = sqrt(1 + (co->raydirx * co->raydirx) /
	(co->raydiry * co->raydiry));
	return (*co);
}

t_img_coord		dir_dist_finder(t_img_coord *co)
{
	if (co->raydirx < 0)
	{
		co->etapex = -1;
		co->dist_murx = (co->rayposx - co->mapx) * co->dist2murx;
	}
	else
	{
		co->etapex = 1;
		co->dist_murx = (co->mapx + 1.0 - co->rayposx) * co->dist2murx;
	}
	if (co->raydiry < 0)
	{
		co->etapey = -1;
		co->dist_mury = (co->rayposy - co->mapy) * co->dist2mury;
	}
	else
	{
		co->etapey = 1;
		co->dist_mury = (co->mapy + 1.0 - co->rayposy) * co->dist2mury;
	}
	return (*co);
}

t_img_coord		dda_calc(t_img_coord *co)
{
	int			touche;

	touche = 0;
	while (touche == 0)
	{
		if (co->dist_murx < co->dist_mury)
		{
			co->dist_murx += co->dist2murx;
			co->mapx += co->etapex;
			co->hori_verti = 0;
		}
		else
		{
			co->dist_mury += co->dist2mury;
			co->mapy += co->etapey;
			co->hori_verti = 1;
		}
		if (co->mapi.mapp[co->mapy][co->mapx] == '1')
			touche = 1;
	}
	return (*co);
}
