/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:46:21 by user42            #+#    #+#             */
/*   Updated: 2020/06/18 14:36:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img_coord		position_south(t_img_coord co)
{
	co.dirx = 0;
	co.diry = 1;
	co.planex = 0.66;
	co.planey = 0;
	return (co);
}

t_img_coord		position_north(t_img_coord co)
{
	co.dirx = 0;
	co.diry = -1;
	co.planex = -0.66;
	co.planey = 0;
	return (co);
}

t_img_coord		position_east(t_img_coord co)
{
	co.dirx = 1;
	co.diry = 0;
	co.planex = 0;
	co.planey = 0.66;
	return (co);
}

t_img_coord		position_west(t_img_coord co)
{
	co.dirx = -1;
	co.diry = 0;
	co.planex = 0;
	co.planey = 0.66;
	return (co);
}

t_img_coord		init_position(t_img_coord co)
{
	if (co.mapi.position_direction == 'N')
		co = position_north(co);
	if (co.mapi.position_direction == 'S')
		co = position_south(co);
	if (co.mapi.position_direction == 'W')
		co = position_west(co);
	if (co.mapi.position_direction == 'E')
		co = position_east(co);
	return (co);
}
