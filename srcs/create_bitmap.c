/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bitmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:50:52 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/18 15:22:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		create_file_header(t_img_coord *co, int fd)
{
	int		w;
	int		h;
	int		file_size;
	int		data_start;

	w = co->argi.reso_x;
	h = co->argi.reso_y;
	file_size = w * h * 4 + 54;
	data_start = 14 + 40;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &data_start, 4);
}

void		create_info_header_1(t_img_coord *co, int fd)
{
	int		size_header;
	int		w;
	int		h;
	short	plane;
	short	bpp;

	plane = 1;
	w = co->argi.reso_x;
	h = co->argi.reso_y;
	size_header = 40;
	bpp = co->img->bits_per_pixel;
	write(fd, &size_header, 4);
	write(fd, &w, 4);
	write(fd, &h, 4);
	write(fd, &plane, 2);
	write(fd, &bpp, 2);
	write(fd, "\0\0\0\0", 4);
}

void		create_info_header_2(int fd, t_img_coord *co)
{
	int		img_size;
	int		color;
	int		w;
	int		h;

	h = co->argi.reso_y - 1;
	w = co->argi.reso_x;
	img_size = w * h * 4;
	color = 0;
	write(fd, &img_size, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
}

void		create_info_image(t_img_coord *co, int fd)
{
	int		w;
	int		h;
	int		y;
	int		r;
	int		x;

	w = co->argi.reso_x;
	h = co->argi.reso_y;
	y = h - 1;
	r = 0x00ffffff;
	while (y >= 0)
	{
		x = 0;
		while (x < w)
		{
			r = (*(int*)(co->img->addr + (y * co->img->line_length + (x * 4))));
			write(fd, &r, 4);
			x++;
		}
		y--;
	}
}

void		create_bmp(t_img_coord *co)
{
	char	*titre;
	int		fd;

	titre = "first_image.bmp";
	put_color("\033[038;5:212m", "\nSAVE under first_image.bmp\n");
	fd = open(titre, O_CREAT | O_WRONLY, 00700);
	create_file_header(co, fd);
	create_info_header_1(co, fd);
	create_info_header_2(fd, co);
	create_info_image(co, fd);
}
