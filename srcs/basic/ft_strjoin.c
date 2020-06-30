/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:16:24 by fcoudert          #+#    #+#             */
/*   Updated: 2020/05/23 22:50:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	ss1;
	size_t	ss2;
	char	*s3;

	if (s1)
	{
		i = 0;
		j = 0;
		ss1 = ft_strlen((char *)s1);
		ss2 = ft_strlen((char *)s2);
		if (!(s3 = malloc(sizeof(char) * (ss1 + ss2 + 1))))
			return (0);
		while (i < (ss1))
		{
			s3[i] = s1[i];
			i++;
		}
		while (j < (ss2))
			s3[i++] = s2[j++];
		s3[i] = '\0';
		return (s3);
	}
	return (NULL);
}
