/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:12:13 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/25 21:19:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strcmp_c(char *p_src, char p_target)
{
	int	i;

	i = 0;
	if (p_src == NULL || p_target == '\0')
		return (0);
	while (p_src[i] != '\0')
	{
		if (p_src[i] == p_target)
			return (1);
		i++;
	}
	return (0);
}
