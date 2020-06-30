/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_textured_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:50:52 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/18 15:22:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img_coord	dist_heigh_calc(t_img_coord *co)
{
	if (co->hori_verti == 0)
	{
		co->longueur_mur = fabs((co->mapx - co->rayposx +
		(1 - co->etapex) / 2) / co->raydirx);
	}
	else
	{
		co->longueur_mur = fabs((co->mapy - co->rayposy +
		(1 - co->etapey) / 2) / co->raydiry);
	}
	co->hauteur_mur = (int)(co->argi.reso_y / co->longueur_mur);
	return (*co);
}

t_img_coord	start_end_calc(t_img_coord *co)
{
	co->drawstart = -co->hauteur_mur / 2 + co->argi.reso_y / 2;
	if (co->drawstart < 0)
		co->drawstart = 0;
	co->drawend = co->hauteur_mur / 2 + co->argi.reso_y / 2;
	if (co->drawend >= co->argi.reso_y)
		co->drawend = co->argi.reso_y - 1;
	return (*co);
}

t_img_coord	verif_3d(t_img_coord *co)
{
	if (co->drawend < 0)
		co->drawend = co->argi.reso_y;
	else if (co->drawend > co->argi.reso_y)
		co->drawend = co->argi.reso_y;
	if (co->drawstart < 0)
		co->drawstart = 0;
	else if (co->drawstart > co->argi.reso_y)
		co->drawstart = co->argi.reso_y;
	return (*co);
}

t_img_coord	draw_text(t_img_coord *co)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (co->text[j]->error == 1)
		{
			co->text[j]->step = 1.0 * co->text[j]->height / co->hauteur_mur;
			co->text[j]->tex_pos = (co->drawstart -
			co->argi.reso_y / 2 + co->hauteur_mur / 2) * co->text[j]->step;
		}
		j++;
	}
	return (*co);
}

t_img_coord	draw_3d(t_img_coord *co)
{
	int	i;
	int	e;

	verif_3d(co);
	i = 0;
	e = co->drawend;
	while (i < co->drawstart && i < (co->argi.reso_y / 2))
	{
		my_mlx_pixel_put(co->img, co->x, i, co->color_ceiling);
		i++;
	}
	draw_text(co);
	while (i < e)
	{
		co->i = i;
		draw_texture(co);
		i++;
	}
	while (i < co->argi.reso_y)
	{
		my_mlx_pixel_put(co->img, co->x, i, co->color_floor);
		i++;
	}
	return (*co);
}
