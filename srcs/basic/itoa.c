/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:22:05 by fcoudert          #+#    #+#             */
/*   Updated: 2020/03/10 13:54:39 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t				ft_count(int c)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	d;

	a = 10;
	d = (unsigned)c;
	i = 0;
	if (c == 0)
		return (1);
	if (c < 0)
	{
		d = -c;
		i++;
	}
	while (d > 0)
	{
		d = d / a;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	a;
	char			*tab1;

	i = n;
	size = ft_count(n);
	a = size;
	if (!(tab1 = malloc(sizeof(char) * (size + 1))))
		return (0);
	if (n == 0)
		tab1[0] = 0;
	if (n < 0)
	{
		i = -n;
	}
	while (a--)
	{
		tab1[a] = (i % 10) + '0';
		i = i / 10;
	}
	if (n < 0)
		tab1[0] = '-';
	tab1[size] = '\0';
	return (tab1);
}
