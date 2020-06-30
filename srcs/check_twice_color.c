/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_twice_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/23 19:53:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_twice_color_f(t_args *args)
{
	if (args->color_floor_r != -1 || args->color_floor_b != -1 ||
	args->color_floor_g != -1)
	{
		put_color(RED, "\nError\n floor's color is filled twice");
		exit(0);
	}
}

void		check_twice_color_c(t_args *args)
{
	if (args->color_ceiling_r != -1 || args->color_ceiling_b != -1 ||
	args->color_ceiling_g != -1)
	{
		put_color(RED, "\nError\n ceiling's color is filled twice");
		exit(0);
	}
}
