/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 22:05:16 by user42            #+#    #+#             */
/*   Updated: 2020/06/25 22:03:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*which_texture(int a, t_img_coord *co)
{
	if (a == 0)
		return (co->argi.text_north);
	else if (a == 1)
		return (co->argi.text_south);
	else if (a == 2)
		return (co->argi.text_east);
	else if (a == 3)
		return (co->argi.text_west);
	return (NULL);
}

t_img_coord	*load_textures(t_img_coord *co)
{
	char	*path;
	t_text	*text;

	while (co->count < 4)
	{
		text = malloc(sizeof(t_text));
		if (texture_valid(co, co->count) == 1)
		{
			path = which_texture(co->count, co);
			text->mlx = co->mlx.mlx;
			text->error = 1;
			if (!(text->img = mlx_xpm_file_to_image(text->mlx, path,
			&text->width, &text->height)))
				text->error = 0;
			if (text->error == 1 && !(text->addr = mlx_get_data_addr(text->img,
			&text->bpp, &text->line_length, &text->endian)))
				text->error = 0;
		}
		else
			text->error = 0;
		error_check(text->error);
		co->text[co->count] = text;
		co->count++;
	}
	return (co);
}

int			which_wall(t_img_coord *co)
{
	if (co->hori_verti == 0)
	{
		if (co->raydirx > 0)
			return (2);
		else
			return (3);
	}
	if (co->hori_verti == 1)
	{
		if (co->raydiry < 0)
			return (1);
		else
			return (0);
	}
	return (2);
}

int			which_color(t_img_coord *co)
{
	if (co->hori_verti == 0)
	{
		if (co->raydirx > 0)
			return (0x00FAB8DE);
		else
			return (0x006AD9FF);
	}
	if (co->hori_verti == 1)
	{
		if (co->raydiry < 0)
			return (0x00BAB3FA);
		else
			return (0x00F0DA99);
	}
	return (0x0054145E);
}

void		draw_texture(t_img_coord *co)
{
	int		texy;
	int		i;
	int		color;

	i = which_wall(co);
	if (co->text[i]->error == 1)
	{
		texy = (int)co->text[i]->tex_pos & (co->text[i]->height - 1);
		co->text[i]->tex_pos += co->text[i]->step;
		color = (*(int*)(co->text[i]->addr +
		(4 * co->text[i]->texx) + (4 * co->text[i]->width * texy)));
	}
	else
		color = which_color(co);
	my_mlx_pixel_put(co->img, co->x, co->i, color);
}
