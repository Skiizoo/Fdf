/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 18:02:04 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 16:23:44 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

int		error(char *msg)
{
	ft_putendl(msg);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx	*fdf;
	int		fd;

	argc = 2;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (error("invalid file"));
	if (!(fdf = init("Fdf tbroggi@le-101")))
		return (error("error at initialization"));
	if (!(fdf->map = get_map(fd)))
		return (error("error"));
	draw_window(fdf);
	mlx_key_hook(fdf->window, key_hook, fdf);
	mlx_mouse_hook(fdf->window, mouse_hook, fdf);
	mlx_loop(fdf->mlx);
	del(&fdf);
	return (0);
}
