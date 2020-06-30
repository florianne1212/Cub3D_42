/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:50:52 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/18 15:22:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		move_forward(t_img_coord *co)
{
	char	at;
	double	next;
	double	movespeed;

	movespeed = 0.02;
	next = co->posy + co->diry * movespeed;
	at = co->mapi.mapp[(int)next][(int)co->posx];
	if (at != '1' && at != ' ' && at != '2')
		co->posy = next;
	next = co->posx + co->dirx * movespeed;
	at = co->mapi.mapp[(int)co->posy][(int)next];
	if (at != '1' && at != ' ' && at != '2')
		co->posx = next;
	co->x = 0;
	return (1);
}

void	move_backward(t_img_coord *co)
{
	char	at;
	double	next;
	double	movespeed;

	movespeed = 0.02;
	next = co->posy - co->diry * movespeed;
	at = co->mapi.mapp[(int)next][(int)co->posx];
	if (at != '1' && at != ' ' && at != '2')
		co->posy = next;
	next = co->posx - co->dirx * movespeed;
	at = co->mapi.mapp[(int)co->posy][(int)next];
	if (at != '1' && at != ' ' && at != '2')
		co->posx = next;
	co->x = 0;
}

void	move_right(t_img_coord *co)
{
	char	at;
	double	next;
	double	movespeed;

	movespeed = 0.02;
	next = co->posy - co->planey * movespeed;
	at = co->mapi.mapp[(int)next][(int)co->posx];
	if (at != '1' && at != ' ' && at != '2')
		co->posy = next;
	next = co->posx - co->planex * movespeed;
	at = co->mapi.mapp[(int)co->posy][(int)next];
	if (at != '1' && at != ' ' && at != '2')
		co->posx = next;
	co->x = 0;
}

void	move_left(t_img_coord *co)
{
	char	at;
	double	next;
	double	movespeed;

	movespeed = 0.02;
	next = co->posy + co->planey * movespeed;
	at = co->mapi.mapp[(int)next][(int)co->posx];
	if (at != '1' && at != ' ' && at != '2')
		co->posy = next;
	next = co->posx + co->planex * movespeed;
	at = co->mapi.mapp[(int)co->posy][(int)next];
	if (at != '1' && at != ' ' && at != '2')
		co->posx = next;
	co->x = 0;
}
