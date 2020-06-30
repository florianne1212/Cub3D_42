/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_i_j.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 08:21:52 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/25 22:09:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			find_j(char *line, int i)
{
	int j;

	j = 0;
	while (line[i + j + 2] != '\0')
		j++;
	return (j);
}

int			find_i(char *line, int e, int nb)
{
	int i;

	i = 0;
	while (ft_isspace(line[e + i + nb]) == 1)
		i++;
	return (i);
}

void		verif_texture(t_args *args)
{
	if (args->error_north == -1)
	{
		put_color("\033[33m", "\nError\n missing path for texture");
		exit(0);
	}
	if (args->error_south == -1)
	{
		put_color("\033[33m", "\nError\n missing path for texture");
		exit(0);
	}
	if (args->error_west == -1)
	{
		put_color("\033[33m", "\nError\n missing path for texture");
		exit(0);
	}
	if (args->error_east == -1)
	{
		put_color("\033[33m", "\nError\n missing path for texture");
		exit(0);
	}
}

void		save(t_img_coord *co)
{
	if (co->argi.save == 1)
	{
		create_bmp(co);
		stop_all(co);
	}
}

void		error_check(int error)
{
	if (error == 0)
	{
		put_color("\033[33m", "\nError\n problem in texture");
		exit(0);
	}
}
