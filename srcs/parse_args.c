/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:39:11 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/18 15:16:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_args					create_bis(t_args args)
{
	args.ready_count = 0;
	args.error_west = -1;
	args.error_east = -1;
	args.error_north = -1;
	args.error_south = -1;
	args.error_sprite = -1;
	args.set_p = -1;
	return (args);
}

t_args					create_t_args(t_args args)
{
	args.buf = NULL;
	args.reso_x = -1;
	args.reso_y = -1;
	args.text_north = NULL;
	args.text_west = NULL;
	args.text_east = NULL;
	args.text_south = NULL;
	args.text_sprite = NULL;
	args.color_floor_r = -1;
	args.color_floor_g = -1;
	args.color_floor_b = -1;
	args.color_ceiling_r = -1;
	args.color_ceiling_g = -1;
	args.color_ceiling_b = -1;
	args.ready = 0;
	args.ready_s = 0;
	args.ready_j = 0;
	args = create_bis(args);
	return (args);
}

size_t					ft_else(char *line, int e, t_args *args)
{
	if (ft_isspace(line[e]) == 1 || line[e] == 0 || line[e] == 32)
		return (0);
	else
	{
		put_color(RED, "\nERrror\n wrong char in your .cub file");
		exit(0);
		args->save = 0;
	}
	return (0);
}

void					set_funct_args(t_args_funct *funct_args)
{
	size_t				i;

	i = 0;
	while (i < 254)
	{
		funct_args[i] = ft_else;
		i++;
	}
	funct_args[0] = ft_else;
	funct_args['R'] = ft_resolution;
	funct_args['N'] = ft_texture_north;
	funct_args['W'] = ft_texture_west;
	funct_args['E'] = ft_texture_east;
	funct_args['S'] = ft_s_case;
	funct_args['F'] = ft_floor_color;
	funct_args['C'] = ft_color_ceilling;
}

t_args					ft_parse_arg(char *line, t_args args)
{
	static t_args_funct	funct_args[255] = {NULL};
	int					i;

	if (args.set_p == -1)
	{
		set_funct_args(funct_args);
		args.set_p = 1;
	}
	i = 0;
	args.buf = line;
	while (i < ft_strlen(line))
	{
		if (funct_args[(int)line[i]] != NULL)
			i += funct_args[(int)line[i]](line, i, &args);
		i++;
	}
	return (args);
}
