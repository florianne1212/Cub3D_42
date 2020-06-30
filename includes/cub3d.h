/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:47:52 by fcoudert          #+#    #+#             */
/*   Updated: 2020/06/25 22:05:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 50
# define RED "\033[31m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "math.h"
# include "mlx.h"

typedef struct		s_text
{
	void			*mlx;
	void			*mlx_win;
	int				bpp;
	int				line_length;
	int				endian;
	char			*addr;
	void			*img;
	int				width;
	int				height;
	int				texx;
	int				i;
	double			step;
	double			tex_pos;
	int				error;
}					t_text;

typedef struct		s_text_sprite
{
	void			*mlx;
	void			*mlx_win;
	int				bpp;
	int				line_length;
	int				endian;
	char			*addr;
	void			*img;
	int				width;
	int				height;
	int				texx;
	int				i;
	double			step;
	double			tex_pos;
	int				error;
}					t_text_sprite;

typedef struct		s_args
{
	char			*buf;
	int				reso_x;
	int				reso_y;
	char			*cub_file;
	char			*text_north;
	char			*text_south;
	char			*text_west;
	char			*text_east;
	char			*text_sprite;
	int				error_north;
	int				error_south;
	int				error_west;
	int				error_east;
	int				error_sprite;
	int				color_floor_r;
	int				color_floor_g;
	int				color_floor_b;
	int				color_ceiling_r;
	int				color_ceiling_g;
	int				color_ceiling_b;
	int				save;
	int				ready;
	int				ready_j;
	int				ready_s;
	int				ready_count;
	int				set_p;
}					t_args;

typedef struct		s_sprite
{
	int				x;
	int				y;
}					t_sprite;

typedef struct		s_map
{
	char			**mapp;
	int				width_map;
	int				height_map;
	int				position_x;
	int				position_y;
	char			position_direction;
	int				number_sprite;
	t_sprite		*sprite;
}					t_map;

typedef	struct		s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				height;
	int				width;
}					t_img;

typedef	struct		s_key
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				ro_right;
	int				ro_left;
}					t_key;

typedef	struct		s_mlx_coord
{
	void			*mlx;
	void			*mlx_win;
	int				*size_x;
	int				*size_y;

}					t_mlx_coord;

typedef	struct		s_plan2d
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				height;
	int				width;
}					t_plan2d;

typedef	struct		s_calc_sprite
{
	double			sprite_x;
	double			sprite_y;
	double			invdet;
	double			transformx;
	double			transformy;
	int				scren_x;
	int				height;
	int				width;
	int				drawstarty;
	int				drawendy;
	int				drawstartx;
	int				drawendx;
}					t_calc_sprite;

typedef struct		s_img_coord
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			camerax;
	double			dist_murx;
	double			dist_mury;
	double			dist2murx;
	double			dist2mury;
	double			longueur_mur;
	double			wallx;
	int				hauteur_mur;
	int				etapex;
	int				etapey;
	int				hori_verti;
	int				mapx;
	int				mapy;
	int				i;
	int				x;
	int				drawstart;
	int				drawend;
	int				color_floor;
	int				color_ceiling;
	int				count;
	double			*buf_sprit;
	int				*sprite_order;
	double			*spr_dist;
	t_key			*key;
	t_text_sprite	*text_sp;
	t_calc_sprite	*calc;
	t_text			*text[3];
	t_plan2d		*plan2d;
	t_mlx_coord		mlx;
	t_img			*img;
	t_args			argi;
	t_map			mapi;
}					t_img_coord;

typedef struct		s_bitmap
{
	char			*type;
	int				file_size;
	int				reserved1;
	int				reserved2;
	int				offset;
	int				size_header;
	int				width;
	int				height;
	int				planes;
	int				bit_count;
	int				compression;
	int				image_size;
	int				ppm_x;
	int				ppm_y;
	int				color_used;
	int				color_impo;
}					t_bitmap;

typedef	void	(*t_map_funct)(t_map *, int a, int o);
typedef	size_t	(*t_args_funct)(char *, int, t_args *);

int					ft_strcmp(char *s1, char *s2);
size_t				ft_texture_west(char *line, int e, t_args *args);
size_t				ft_texture_east(char *line, int e, t_args *args);
size_t				ft_texture_north(char *line, int e, t_args *args);
size_t				ft_texture_south(char *line, int e, t_args *args);
size_t				ft_texture_sprite(char *line, int e, t_args *args);
size_t				ft_floor_color(char *line, int e, t_args *args);
size_t				ft_color_ceilling(char *line, int e, t_args *args);
size_t				ft_resolution(char *line, int e, t_args *args);
size_t				ft_s_case(char *line, int e, t_args *args);
int					ft_check_path_text(char *line, int e, char *path);
size_t				ft_s_case(char *line, int e, t_args *args);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa_base(unsigned long nbr, char *base);
int					get_next_line(int fd, char **line);
int					ft_strlen(char *str);
char				*ft_strdup(const char *s1);
char				*ft_strxjoin(char const *s1, char const *s2);
int					ft_atoi(const char *str);
size_t				ft_count(int c);
int					ft_isspace(char c);
void				ft_putstr(char *str);
int					ft_strcmp_c(char *p_src, char p_target);
int					ft_atoi_test(const char *str);
int					eol(char *buffer);
int					str_len(char *str);
char				*sub_str(char *buffer, int start, int end);
char				*add_suffixe(char *buffer, char *readed);
char				*sub_str_and_free(char *buffer, int start, int end);
char				*ft_strnew(size_t size, char c);
t_args				ft_parse_arg(char *line, t_args args);
void				set_funct_args(t_args_funct *funct_args);
t_args				create_t_args(t_args args);
void				set_funct_map(t_map_funct *funct_map);
t_map				ft_parse_map(int i, int j, int count, char *path);
int					check_right(t_map *map, int x, int y);
int					check_left(t_map *map, int x, int y);
int					check_above(t_map *map, int x, int y);
int					check_below(t_map *map, int x, int y);
void				ft_position_n(t_map *map, int x, int y);
void				ft_position_s(t_map *map, int x, int y);
void				ft_position_w(t_map *map, int x, int y);
void				ft_position_e(t_map *map, int x, int y);
void				ft_sprite(t_map *map, int x, int y);
void				ft_check_borders(t_map *map, int x, int y);
void				ft_graph(t_args argy, t_map mapy);
void				my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_img_coord			init_imgco(t_img_coord imgco, t_map mapy);
t_img_coord			dir_dist_finder(t_img_coord *imgco);
t_img_coord			dda_calc(t_img_coord *co);
t_img_coord			dist_heigh_calc(t_img_coord *co);
t_img_coord			start_end_calc(t_img_coord *co);
t_img_coord			draw_3d(t_img_coord *co);
t_img_coord			manage_3d(t_img_coord *co);
int					moov(int keycode, t_img_coord *co);
void				manage_2d(t_img_coord *co);
t_img_coord			init_position(t_img_coord co);
t_img_coord			init_color(t_img_coord co);
int					ft_atoi_base(char *str, char *base);
t_img_coord			*load_textures(t_img_coord *co);
void				draw_texture(t_img_coord *co);
void				texture_calc(t_img_coord *co);
void				draw_minimap(t_img_coord *co);
void				ft_tab_sprite(t_map *map);
t_text_sprite		*load_sprite(t_img_coord *co);
void				sprite_cast(t_img_coord *co);
void				put_color(char *color, char *str);
int					key_released(int keycode, t_img_coord *co);
int					key_pressed(int keycode, t_img_coord *co);
int					move_forward(t_img_coord *co);
void				move_backward(t_img_coord *co);
void				rotate_right(t_img_coord *co);
void				rotate_left(t_img_coord *co);
void				move_right(t_img_coord *co);
void				move_left(t_img_coord *co);
void				create_bmp(t_img_coord *co);
char				*put_path(int i, char *path, char *line);
int					stop_all(t_img_coord *co);
t_img_coord			init_calc_finder(t_img_coord *co, t_args argy);
int					texture_valid(t_img_coord *co, int i);
void				sprite_cast_3(t_img_coord *co);
void				sprite_cast_2(t_img_coord *co, int i);
void				tri_sprite(t_img_coord *co);
void				sprite_cast_1(t_img_coord *co);
int					find_j(char *line, int i);
int					find_i(char *line, int e, int nb);
char				*ft_strdupi(const char *s1);
void				check_pos(t_map *map);
int					ft_empty_line(char *line);
int					ft_compare(int j, int i);
t_args				check_resolution(t_args argy, t_mlx_coord mlxco);
int					check_twice_west(t_args *args, char *line, int e);
int					check_twice_north(t_args *args, char *line, int e);
int					check_twice_south(t_args *args, char *line, int e);
int					check_twice_east(t_args *args, char *line, int e);
int					check_twice_sprite(t_args *args, char *line, int e);
void				verif_texture(t_args *args);
void				check_twice_color_c(t_args *args);
void				check_twice_color_f(t_args *args);
t_map				full_check(t_map map, int i, int j);
void				save(t_img_coord *co);
t_map				ft_check_map(t_map *map, int i, int j);
t_args				check_args(t_args argy, int argc, char **argv);
char				*check_cub(char *argv);
void				error_check(int error);
int					valid_file(t_args args);

#endif
