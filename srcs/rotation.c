/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:50:52 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/18 15:22:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_img_coord *co)
{
	double	old_dirx;
	double	old_planex;
	double	rotspeed;

	rotspeed = 0.01;
	old_dirx = co->dirx;
	old_planex = co->planex;
	co->dirx = co->dirx * cos(rotspeed) - co->diry * sin(rotspeed);
	co->diry = old_dirx * sin(rotspeed) + co->diry * cos(rotspeed);
	co->planex = co->planex * cos(rotspeed) - co->planey * sin(rotspeed);
	co->planey = old_planex * sin(rotspeed) + co->planey * cos(rotspeed);
	co->x = 0;
}

void	rotate_left(t_img_coord *co)
{
	double	old_dirx;
	double	old_planex;
	double	rotspeed;

	rotspeed = -0.01;
	old_dirx = co->dirx;
	old_planex = co->planex;
	co->dirx = co->dirx * cos(rotspeed) - co->diry * sin(rotspeed);
	co->diry = old_dirx * sin(rotspeed) + co->diry * cos(rotspeed);
	co->planex = co->planex * cos(rotspeed) - co->planey * sin(rotspeed);
	co->planey = old_planex * sin(rotspeed) + co->planey * cos(rotspeed);
	co->x = 0;
}
