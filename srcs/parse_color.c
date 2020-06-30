/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:27:03 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/25 21:22:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_value_color_f(char *line, int e, t_args *args)
{
	int		d;
	int		result;

	d = 0;
	result = 0;
	while (e < ft_strlen(line) && ft_strcmp_c("01234567789-,", line[e]) == 1)
	{
		result = ft_atoi(&line[e]);
		if (result > 255 || result < 0)
		{
			put_color(RED, "\nError\n wrong value for the floor color");
			exit(0);
		}
		if (d == 0)
			args->color_floor_r = result;
		else if (d == 1)
			args->color_floor_g = result;
		else if (d == 2)
			args->color_floor_b = result;
		e += ft_count(result) + 1;
		d++;
	}
	return (e - 2);
}

size_t		ft_floor_color(char *line, int e, t_args *args)
{
	int		i;
	int		r;
	int		j;

	r = 0;
	j = 0;
	i = 0;
	if (line[e] == 'F' && (ft_isspace(line[e + 1]) == 1 || line[e + 1] == 0))
	{
		check_twice_color_f(args);
		i = find_i(line, e, 2);
		while (line[e + i + j + 2] != '\0')
		{
			if (line[e + i + j + 2] == ',')
				r++;
			j++;
		}
		if (r != 2)
		{
			put_color(RED, "\nError\n wrong number of argument floor color");
			exit(0);
		}
		j = ft_value_color_f(line, (e + i + 2), args);
	}
	return (j);
}

int			ft_value_color_c(char *line, int e, t_args *args)
{
	int		d;
	int		result;

	d = 0;
	result = 0;
	while (e < ft_strlen(line) && ft_strcmp_c("01234567789-,", line[e]) == 1)
	{
		result = ft_atoi(&line[e]);
		if (result > 255 || result < 0)
		{
			put_color(RED, "\nError\n wrong value for the ceiling's color");
			exit(0);
		}
		if (d == 0)
			args->color_ceiling_r = result;
		else if (d == 1)
			args->color_ceiling_g = result;
		else if (d == 2)
			args->color_ceiling_b = result;
		e += ft_count(result) + 1;
		d++;
	}
	return (e);
}

size_t		ft_color_ceilling(char *line, int e, t_args *args)
{
	int		i;
	int		r;
	int		j;

	r = 0;
	j = 0;
	i = 0;
	if (line[e] == 'C' && (ft_isspace(line[e + 1]) == 1 || line[e + 1] == 0))
	{
		check_twice_color_c(args);
		i = find_i(line, e, 2);
		while (line[e + i + j + 2] != '\0')
		{
			if (line[e + i + j + 2] == ',')
				r++;
			j++;
		}
		if (r != 2)
		{
			put_color(RED, "\nError\n wrong number of argument ceiling color");
			exit(0);
		}
		j = ft_value_color_c(line, (e + i + 2), args);
	}
	return (j - 2);
}
