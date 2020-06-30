/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:50:52 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/25 22:03:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_check(t_args *args)
{
	if (args->reso_x == -1 || args->reso_y == -1 || args->text_sprite == NULL ||
	args->color_floor_r == -1 || args->color_floor_b == -1 ||
	args->color_floor_g == -1 || args->color_ceiling_r == -1 ||
	args->color_ceiling_b == -1 || args->color_ceiling_g == -1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	return (0);
}

void		verif_args(t_args *args)
{
	if (args->reso_y == -1 || args->reso_x == -1)
	{
		put_color(RED, "\nError\n wrong format for resolution or missing");
		exit(0);
	}
	if (args->text_sprite == NULL)
	{
		put_color(RED, "\nError\n missing path for sprite");
		exit(0);
	}
	if (args->color_ceiling_r == -1 || args->color_ceiling_b == -1 ||
	args->color_ceiling_g == -1)
	{
		put_color(RED, "\nError\n wrong format for color or missing");
		exit(0);
	}
	if (args->color_floor_r == -1 || args->color_floor_b == -1 ||
	args->color_floor_g == -1)
	{
		put_color(RED, "\nError\n wrong format for color or missing");
		exit(0);
	}
	verif_texture(args);
}

t_args		empty(t_args args, int fd, char *line)
{
	int i;

	verif_args(&args);
	if (ft_empty_line(line) == 1)
	{
		put_color(RED, "\nError\n something is wrong ");
		free(line);
		exit(0);
	}
	free(line);
	while ((i = get_next_line(fd, &line)) == 1 && ft_empty_line(line) == 0)
	{
		args.ready_count++;
		free(line);
		line = NULL;
	}
	free(line);
	return (args);
}

t_args		parse_cub(t_args args)
{
	int		fd;
	char	*line;
	int		i;

	args = create_t_args(args);
	i = 1;
	fd = valid_file(args);
	while ((i = get_next_line(fd, &line)) == 1 && ft_check(&args) == 1)
	{
		args = ft_parse_arg(line, args);
		args.ready_count++;
		free(line);
	}
	args = empty(args, fd, line);
	while ((i = get_next_line(fd, &line)) > 0 && ft_check(&args) == 0)
	{
		args.ready_s = ft_compare(ft_strlen(line), args.ready_s);
		args.ready_j++;
		free(line);
	}
	free(line);
	args.ready_j += 2;
	close(fd);
	return (args);
}

int			main(int argc, char **argv)
{
	t_map	mapy;
	t_args	argy;

	argy.save = 0;
	if (argc > 0)
		put_color("\033[36m", "\nHello\n");
	if (argc == 1)
	{
		put_color(RED, "\nError\n too few arguments");
		exit(0);
	}
	argy = check_args(argy, argc, argv);
	argy = parse_cub(argy);
	if (ft_check(&argy) == 0 && argy.ready_j > 0)
		mapy = ft_parse_map(argy.ready_j, argy.ready_s, argy.ready_count,
		argy.cub_file);
	if (ft_check(&argy) == 0 && argy.ready_j > 0)
		ft_graph(argy, mapy);
	return (1);
}
