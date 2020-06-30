/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:19:37 by fcoudert          #+#    #+#             */
/*   Updated: 2020/05/23 22:50:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t				ft_count_base(unsigned long c, char *base)
{
	unsigned int	i;
	unsigned int	a;
	unsigned long	d;

	a = ft_strlen(base);
	d = c;
	i = 0;
	if (c == 0)
		return (1);
	while (d != 0)
	{
		d = d / a;
		i++;
	}
	return (i);
}

char				*ft_itoa_base(unsigned long nbr, char *base)
{
	unsigned int	size;
	unsigned long	i;
	unsigned int	a;
	char			*tab1;

	i = nbr;
	size = ft_count_base(nbr, base);
	a = size;
	if (!(tab1 = malloc(sizeof(char) * (size + 1))))
		return (0);
	if (nbr == 0)
		tab1[0] = 0;
	while (a--)
	{
		tab1[a] = base[i % ft_strlen(base)];
		i = i / ft_strlen(base);
	}
	tab1[size] = '\0';
	return (tab1);
}
