/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:50:52 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/18 15:22:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		put_color(char *color, char *str)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr("\033[37m");
}
