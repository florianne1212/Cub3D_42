/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 22:05:16 by user42            #+#    #+#             */
/*   Updated: 2020/06/18 15:09:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		texture_valid(t_img_coord *co, int i)
{
	if (i == 0 && co->argi.error_north == 1)
		return (1);
	if (i == 1 && co->argi.error_south == 1)
		return (1);
	if (i == 2 && co->argi.error_east == 1)
		return (1);
	if (i == 3 && co->argi.error_west == 1)
		return (1);
	return (0);
}
