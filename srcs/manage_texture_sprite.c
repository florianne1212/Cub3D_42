/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_texture_sprite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 22:05:16 by user42            #+#    #+#             */
/*   Updated: 2020/06/24 18:58:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				texture_calc(t_img_coord *co)
{
	int				i;

	i = 0;
	while (i < 4)
	{
		if (co->text[i]->error == 1)
		{
			if (co->hori_verti == 0)
				co->wallx = co->posy + co->longueur_mur * co->raydiry;
			else
				co->wallx = co->posx + co->longueur_mur * co->raydirx;
			co->wallx -= floor((co->wallx));
			co->text[i]->texx = (int)(co->wallx * (co->text[i]->width));
			if (co->hori_verti == 0 && co->raydirx > 0)
				co->text[i]->texx = co->text[i]->width - co->text[i]->texx - 1;
			if (co->hori_verti == 1 && co->raydiry < 0)
				co->text[i]->texx = co->text[i]->width - co->text[i]->texx - 1;
		}
		i++;
	}
}

void				print_error(void)
{
	put_color(RED, "\nError\n error with sprite file");
	exit(0);
}

t_text_sprite		*load_sprite(t_img_coord *co)
{
	char			*path;
	t_text_sprite	*text_sp;

	if (!(text_sp = malloc(sizeof(t_text_sprite))))
		return (NULL);
	if (co->argi.error_sprite == 1)
	{
		path = co->argi.text_sprite;
		text_sp->mlx = co->mlx.mlx;
		text_sp->error = 1;
		if (!(text_sp->img = mlx_xpm_file_to_image(text_sp->mlx, path,
		&text_sp->width, &text_sp->height)))
			text_sp->error = 0;
		if (text_sp->error == 1 && !(text_sp->addr = mlx_get_data_addr(
			text_sp->img, &text_sp->bpp, &text_sp->line_length,
			&text_sp->endian)))
			text_sp->error = 0;
	}
	else
		text_sp->error = 0;
	if (text_sp->error == 0)
		print_error();
	return (text_sp);
}
