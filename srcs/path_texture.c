/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 08:21:52 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/25 21:51:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_check_path_text(char *line, int e, char *path)
{
	int		i;

	i = 0;
	if (line[e] != 'm' && line[e - 1] != 'p' &&
		line[e - 2] != 'x' && line[e - 3] != '.')
	{
		put_color("\033[33m",
		"\nError\n wrong format for texture");
		exit(0);
	}
	e = 0;
	line[0] = '1';
	if ((i = open(path, O_RDONLY)) == -1)
	{
		put_color("\033[33m",
		"\nError\n texture can't be open");
		exit(0);
	}
	else
		close(i);
	return (1);
}

size_t		ft_texture_north(char *line, int e, t_args *args)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	if (line[e] == 'N' && line[e + 1] == 'O')
	{
		i = check_twice_north(args, line, e);
		j = find_j(line, (e + i));
		if (!(path = malloc(sizeof(char) * (j + 1))))
			return (0);
		path = put_path(e + i + 2, path, line);
		if (ft_check_path_text(line, (e + i + j + 1), path) == 1)
		{
			args->text_north = path;
			args->error_north = 1;
		}
		else
		{
			args->error_north = 0;
			free(path);
		}
	}
	return (e + i + j + 1);
}

size_t		ft_texture_west(char *line, int e, t_args *args)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	if (line[e] == 'W' && line[e + 1] == 'E')
	{
		i = check_twice_west(args, line, e);
		j = find_j(line, (e + i));
		if (!(path = malloc(sizeof(char) * (j + 1))))
			return (0);
		path = put_path(e + i + 2, path, line);
		if (ft_check_path_text(line, (e + i + j + 1), path) == 1)
		{
			args->text_west = path;
			args->error_west = 1;
		}
		else
		{
			args->error_west = 0;
			free(path);
		}
	}
	return (e + i + j + 1);
}

size_t		ft_texture_east(char *line, int e, t_args *args)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	if (line[e] == 'E' && line[e + 1] == 'A')
	{
		i = check_twice_east(args, line, e);
		j = find_j(line, (e + i));
		if (!(path = malloc(sizeof(char) * (j + 1))))
			return (0);
		path = put_path(e + i + 2, path, line);
		if (ft_check_path_text(line, (e + i + j + 1), path) == 1)
		{
			args->text_east = path;
			args->error_east = 1;
		}
		else
		{
			args->error_east = 0;
			free(path);
		}
	}
	return (e + i + j + 1);
}

size_t		ft_texture_south(char *line, int e, t_args *args)
{
	int		i;
	int		j;
	char	*path;

	j = 0;
	i = 0;
	if (line[e] == 'S' && line[e + 1] == 'O')
	{
		i = check_twice_south(args, line, e);
		j = find_j(line, (e + i));
		if (!(path = malloc(sizeof(char) * (j + 1))))
			return (0);
		path = put_path(e + i + 2, path, line);
		if (ft_check_path_text(line, (e + i + j + 1), path) == 1)
		{
			args->text_south = path;
			args->error_south = 1;
		}
		else
		{
			args->error_south = 0;
			free(path);
		}
	}
	return (e + i + j + 1);
}
