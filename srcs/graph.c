/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 23:47:13 by user42            #+#    #+#             */
/*   Updated: 2020/06/25 21:59:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_key			*init_key(void)
{
	t_key		*key;

	if (!(key = malloc(sizeof(t_key))))
		return (NULL);
	key->w = 0;
	key->s = 0;
	key->a = 0;
	key->d = 0;
	key->ro_left = 0;
	key->ro_right = 0;
	return (key);
}

int				my_loop(t_img_coord *co)
{
	if (co->key->w)
		move_forward(co);
	if (co->key->s)
		move_backward(co);
	if (co->key->a)
		move_left(co);
	if (co->key->d)
		move_right(co);
	if (co->key->ro_left)
		rotate_left(co);
	if (co->key->ro_right)
		rotate_right(co);
	manage_3d(co);
	mlx_do_sync(co->mlx.mlx);
	return (0);
}

t_img			*init_img(t_mlx_coord xco, t_args argy)
{
	t_img		*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	img->img = mlx_new_image(xco.mlx, argy.reso_x, argy.reso_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
	&img->line_length, &img->endian);
	return (img);
}

void			ft_graph(t_args argy, t_map mapy)
{
	t_mlx_coord	xco;
	t_img_coord	imgco;

	xco.mlx = mlx_init();
	argy = check_resolution(argy, xco);
	imgco.argi = argy;
	imgco = init_imgco(imgco, mapy);
	if (argy.save == 0)
		xco.mlx_win = mlx_new_window(xco.mlx, argy.reso_x, argy.reso_y, "cub");
	imgco.key = init_key();
	imgco.img = init_img(xco, argy);
	imgco.mlx = xco;
	imgco.text_sp = load_sprite(&imgco);
	imgco = *load_textures(&imgco);
	if (!(imgco.calc = malloc(sizeof(t_calc_sprite))))
		return ;
	if (!(imgco.buf_sprit = malloc(sizeof(double) * imgco.argi.reso_x)))
		return ;
	imgco = manage_3d(&imgco);
	save(&imgco);
	mlx_hook(imgco.mlx.mlx_win, 2, 1L << 0, key_pressed, &imgco);
	mlx_hook(imgco.mlx.mlx_win, 3, 1L << 1, key_released, &imgco);
	mlx_hook(imgco.mlx.mlx_win, 33, 1L << 17, stop_all, &imgco);
	mlx_loop_hook(xco.mlx, &my_loop, &imgco);
	mlx_loop(xco.mlx);
}
