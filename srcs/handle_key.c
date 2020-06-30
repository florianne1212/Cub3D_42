/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:50:52 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/25 20:29:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(t_img_coord *co)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (co->text[i]->error == 1)
		{
			mlx_destroy_image(co->text[i]->mlx, co->text[i]->img);
			free(co->text[i]);
		}
		i++;
	}
	free(co->argi.cub_file);
}

void	handle_exit(t_img_coord *co)
{
	int i;

	i = 0;
	mlx_destroy_image(co->text_sp->mlx, co->text_sp->img);
	free(co->text_sp);
	free(co->calc);
	free(co->buf_sprit);
	free(co->key);
	free_texture(co);
	while (i < co->mapi.height_map + 1)
	{
		free(co->mapi.mapp[i]);
		i++;
	}
	free(co->mapi.mapp);
	free(co->argi.text_sprite);
	free(co->mapi.sprite);
	free(co->argi.text_west);
	free(co->argi.text_north);
	free(co->argi.text_east);
	free(co->argi.text_south);
	mlx_destroy_image(co->mlx.mlx, co->img->img);
	if (co->argi.save == 0)
		mlx_destroy_window(co->mlx.mlx, co->mlx.mlx_win);
	free(co->img);
}

int		stop_all(t_img_coord *co)
{
	handle_exit(co);
	put_color("\033[36m", "\nGOODBYE \n");
	exit(EXIT_SUCCESS);
}

int		key_pressed(int keycode, t_img_coord *co)
{
	if (keycode == 'w')
		co->key->w = 1;
	if (keycode == 's')
		co->key->s = 1;
	if (keycode == 'd')
		co->key->a = 1;
	if (keycode == 'a')
		co->key->d = 1;
	if (keycode == 65363)
		co->key->ro_left = 1;
	if (keycode == 65361)
		co->key->ro_right = 1;
	if (keycode == 65307)
	{
		stop_all(co);
	}
	return (1);
}

int		key_released(int keycode, t_img_coord *co)
{
	if (keycode == 'w')
		co->key->w = 0;
	if (keycode == 's')
		co->key->s = 0;
	if (keycode == 'd')
		co->key->a = 0;
	if (keycode == 'a')
		co->key->d = 0;
	if (keycode == 65363)
		co->key->ro_left = 0;
	if (keycode == 65361)
		co->key->ro_right = 0;
	return (1);
}
