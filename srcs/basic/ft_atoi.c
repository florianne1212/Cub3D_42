/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 08:22:23 by fcoudert          #+#    #+#             */
/*   Updated: 2020/03/11 15:45:10 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_isspace(char c)
{
	if ((c == ' ') || (c == '\f') ||
			(c == '\n') || (c == '\v') ||
			(c == '\r') || (c == '\t'))
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	long int	i;
	long int	resu;
	long int	sign;
	long int	test;

	i = 0;
	resu = 0;
	sign = 1;
	test = 0;
	while (str[i] != '\0' && ft_isspace(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		test++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
		resu = resu * 10 + (str[i++] - '0');
	if (test > 1)
		return (0);
	return (sign * resu);
}

int				ft_atoi_test(const char *str)
{
	long int	i;
	long int	resu;
	long int	sign;
	long int	test;

	i = 0;
	resu = 0;
	sign = 1;
	test = 0;
	while (str[i] != '\0' && (ft_isspace(str[i]) == 1 || str[i] == 0))
		i++;
	if (str[i] == '\0')
		return (-1);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		test++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
		resu = resu * 10 + (str[i++] - '0');
	if (test > 1)
		return (0);
	return (sign * resu);
}
