/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:49:29 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/18 15:25:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		free_text(t_args *args, char *line)
{
	if (args->text_east != NULL)
		free(args->text_east);
	if (args->text_west != NULL)
		free(args->text_west);
	if (args->text_south != NULL)
		free(args->text_south);
	if (args->text_north != NULL)
		free(args->text_north);
	free(line);
}

int			ft_check_path_sprite(char *line, int e, char *path, t_args *args)
{
	int		i;

	i = 0;
	if (line[e] != 'm' && line[e - 1] != 'p' &&
		line[e - 2] != 'x' && line[e - 3] != '.')
	{
		put_color("\033[31m",
		"\nError\n wrong format for sprite check your path");
		free_text(args, line);
		exit(0);
	}
	e = 0;
	line[0] = '1';
	if ((i = open(path, O_RDONLY)) == -1)
	{
		put_color("\033[31m",
		"\nError\n file can't open for sprite check your path");
		free_text(args, line);
		exit(0);
	}
	else
		close(i);
	return (1);
}

size_t		ft_s_case(char *line, int e, t_args *args)
{
	size_t	i;

	i = 0;
	if (line[e] == 'S' && line[e + 1] == 'O')
		i = ft_texture_south(line, e, args);
	else if (line[e] == 'S' && (ft_isspace(line[e + 1]) == 1 ||
	line[e + 1] == 0))
		i = ft_texture_sprite(line, e, args);
	return (i);
}

char		*put_path(int i, char *path, char *line)
{
	int		j;

	j = 0;
	j = 0;
	while (line[i + j] != '\0')
	{
		path[j] = line[i + j];
		j++;
	}
	path[j] = '\0';
	return (path);
}

size_t		ft_texture_sprite(char *line, int e, t_args *args)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	if (line[e] == 'S' && (ft_isspace(line[e + 1]) == 1 || line[e + 1] == 0))
	{
		i = check_twice_sprite(args, line, e);
		j = find_j(line, (e + i));
		if (!(path = malloc(sizeof(char) * (j + 1))))
			return (0);
		path = put_path(e + i + 2, path, line);
		if (ft_check_path_sprite(line, (e + i + j + 1), path, args) == 1)
		{
			args->text_sprite = path;
			args->error_sprite = 1;
		}
		else
		{
			args->error_sprite = 0;
			free_text(args, line);
		}
	}
	return (e + i + j + 1);
}
