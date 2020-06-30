/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:13:10 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/25 21:49:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*check_cub(char *argv)
{
	char	*cub_file;
	int		i;
	int		j;

	i = 0;
	if (!(cub_file = malloc(sizeof(char) * (ft_strlen(argv) + 1))))
		return (NULL);
	while (argv[i] != '\0')
	{
		cub_file[i] = argv[i];
		i++;
	}
	cub_file[i] = '\0';
	j = ft_strlen(cub_file);
	if (cub_file[j - 1] != 'b' || cub_file[j - 2] != 'u' ||
	cub_file[j - 3] != 'c' || cub_file[j - 4] != '.')
	{
		put_color(RED, "put a .cub file");
		free(cub_file);
		exit(0);
	}
	return (cub_file);
}

t_args		check_args(t_args argy, int argc, char **argv)
{
	if (argc == 2)
		argy.cub_file = check_cub(argv[1]);
	if (argc == 3)
	{
		if (ft_strcmp("--save", argv[2]) == 0)
		{
			argy.cub_file = check_cub(argv[1]);
			argy.save = 1;
		}
		else
		{
			put_color(RED,
			"\nError\n wrong arguments the first one muse be .cub file");
			exit(0);
		}
	}
	if (argc > 3)
	{
		put_color(RED, "\nError\n too many arguments");
		exit(0);
	}
	return (argy);
}

int			valid_file(t_args args)
{
	int fd;

	fd = open(args.cub_file, O_RDONLY);
	if (fd < 0)
	{
		put_color(RED, "invalid cub file");
		free(args.cub_file);
		exit(0);
	}
	return (fd);
}
