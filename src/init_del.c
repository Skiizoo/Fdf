/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_del.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 18:01:58 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 16:23:52 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

t_mlx		*del(t_mlx **fdf)
{
	if ((*fdf)->window)
		mlx_destroy_window((*fdf)->mlx, (*fdf)->window);
	if ((*fdf)->img)
		(*fdf)->img = del_image((*fdf)->mlx, (*fdf)->img);
	ft_memdel((void **)&fdf);
	return (NULL);
}

t_mlx		*init(char *title)
{
	t_mlx	*fdf;

	if (!(fdf = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(fdf->mlx = mlx_init()) ||
		!(fdf->window = mlx_new_window(fdf->mlx, WIN_WIDTH,
			WIN_HEIGHT, title)) ||
		!(fdf->img = new_image(fdf)))
		return (del(&fdf));
	return (fdf);
}
