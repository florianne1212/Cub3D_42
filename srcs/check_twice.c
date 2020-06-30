/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_twice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/23 19:53:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_twice_north(t_args *args, char *line, int e)
{
	int		i;

	if (args->error_north != -1)
	{
		put_color(RED, "\nError\n north's texture has two path");
		exit(0);
	}
	i = find_i(line, e, 2);
	return (i);
}

int			check_twice_south(t_args *args, char *line, int e)
{
	int		i;

	if (args->error_south != -1)
	{
		put_color(RED, "\nError\n south's texture has two path");
		exit(0);
	}
	i = find_i(line, e, 2);
	return (i);
}

int			check_twice_east(t_args *args, char *line, int e)
{
	int		i;

	if (args->error_east != -1)
	{
		put_color(RED, "\nError\n east's texture has two path");
		exit(0);
	}
	i = find_i(line, e, 2);
	return (i);
}

int			check_twice_west(t_args *args, char *line, int e)
{
	int		i;

	if (args->error_west != -1)
	{
		put_color(RED, "\nError\n west's texture has two path");
		exit(0);
	}
	i = find_i(line, e, 2);
	return (i);
}

int			check_twice_sprite(t_args *args, char *line, int e)
{
	int		i;

	if (args->error_sprite != -1)
	{
		put_color(RED, "\nError\n sprite's texture has two path");
		exit(0);
	}
	i = find_i(line, e, 2);
	return (i);
}
