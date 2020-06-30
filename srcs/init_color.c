/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 22:24:56 by user42            #+#    #+#             */
/*   Updated: 2020/06/18 14:35:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			create_rgb_floor(t_img_coord co)
{
	int		r;
	int		g;
	int		b;

	r = co.argi.color_floor_r;
	g = co.argi.color_floor_g;
	b = co.argi.color_floor_b;
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int			create_rgb_ceiling(t_img_coord co)
{
	int		r;
	int		g;
	int		b;

	r = co.argi.color_ceiling_r;
	g = co.argi.color_ceiling_g;
	b = co.argi.color_ceiling_b;
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

t_img_coord	init_color(t_img_coord co)
{
	co.color_floor = create_rgb_floor(co);
	co.color_ceiling = create_rgb_ceiling(co);
	return (co);
}
