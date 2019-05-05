/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 17:55:38 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 11:16:15 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

int			key_hook(int key, t_mlx *fdf)
{
	if (key == 1)
		change_depth(&fdf->map, 0);
	else if (key == 53)
		exit(0);
	else if (key == 69)
		change_depth(&fdf->map, 2);
	else if (key == 78)
		change_depth(&fdf->map, 1);
	else if (key == 123)
		fdf->map->move.x -= 10;
	else if (key == 124)
		fdf->map->move.x += 10;
	else if (key == 125)
		fdf->map->move.y += 10;
	else if (key == 126)
		fdf->map->move.y -= 10;
	draw_window(fdf);
	return (1);
}

int			mouse_hook(int button, int x, int y, t_mlx *fdf)
{
	x = 0;
	y = 0;
	if (button == 5)
	{
		fdf->map->gap.x += 0.5;
		fdf->map->gap.y += 0.33;
		fdf->map->gap.z += 0.05;
	}
	else if (button == 4)
	{
		if (fdf->map->gap.z <= 0.10)
			return (0);
		fdf->map->gap.x -= 0.5;
		fdf->map->gap.y -= 0.33;
		fdf->map->gap.z -= 0.05;
	}
	draw_window(fdf);
	return (1);
}
