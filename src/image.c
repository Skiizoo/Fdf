/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 18:01:48 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 15:50:40 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

void			draw_image(t_image *img, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int *)(img->ptr + ((x + y * WIN_WIDTH) * img->bits)) = color;
}

void			reset_image(t_image *img)
{
	ft_bzero(img->ptr, WIN_WIDTH * WIN_HEIGHT * img->bits);
}

t_image			*del_image(t_mlx *fdf, t_image *img)
{
	if (img)
	{
		if (img->img)
			mlx_destroy_image(fdf->mlx, img->img);
		ft_memdel((void **)&img);
	}
	return (img);
}

t_image			*new_image(t_mlx *fdf)
{
	t_image		*img;

	if (!(img = ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(img->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT)))
		return (del_image(fdf, img));
	img->ptr = mlx_get_data_addr(img->img, &img->bits, &img->s_line,
			&img->endian);
	img->bits /= 8;
	return (img);
}
