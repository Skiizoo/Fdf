/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 18:04:17 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 16:08:37 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# define WIN_WIDTH	2000
# define WIN_HEIGHT	1200
# define ABS(x)     (x < 0 ? -x : x)

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_vector;

typedef struct		s_map
{
	int				width;
	int				height;
	int				min;
	int				max;
	t_pos			start;
	t_pos			move;
	t_vector		gap;
	t_vector		**vectors;
}					t_map;

typedef struct		s_image
{
	void			*img;
	char			*ptr;
	int				bits;
	int				s_line;
	int				endian;
}					t_image;

typedef struct		s_line
{
	t_pos			diff;
	t_pos			pos1;
	t_pos			pos2;
	int				lon;
	int				sho;
}					t_line;

typedef struct		s_mlx
{
	void			*mlx;
	void			*window;
	t_map			*map;
	t_image			*img;
}					t_mlx;

int					key_hook(int key, t_mlx *mlx);
int					mouse_hook(int button, int x, int y, t_mlx *mlx);
t_mlx				*init(char *title);
t_mlx				*del(t_mlx **mlx);
t_map				*get_map(int fd);
void				draw_window(t_mlx *mlx);
void				draw_line(t_mlx *mlx, t_vector start, t_vector end);
void				draw_image(t_image *img, int x, int y, int color);
void				reset_image(t_image *img);
t_image				*del_image(t_mlx *mlx, t_image *img);
t_image				*new_image(t_mlx *mlx);
void				get_depth(t_map **map);
int					get_color(int c1, int c2, double p);
void				get_point_color(t_vector *vector, t_map *map);
double				get_percent(double x0, double x1, double x2);
void				get_gap(t_map *map);
void				change_depth(t_map **map, int i);
int					check_value(char *str);
#endif
