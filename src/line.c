/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 17:56:26 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 15:51:37 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	compare(t_mlx *fdf, t_line line, t_vector start, t_vector end)
{
	int			i;
	int			num;
	t_vector	pos;
	double		p;

	num = line.lon >> 1;
	i = -1;
	pos = start;
	while (++i <= line.lon)
	{
		p = abs(line.diff.x) > abs(line.diff.y) ? get_percent(start.x,
				pos.x, end.x) : get_percent(start.y, pos.y, end.y);
		draw_image(fdf->img, pos.x, pos.y,
				get_color(start.color, end.color, p));
		num += line.sho;
		pos.x += num > line.lon ? line.pos1.x : line.pos2.x;
		pos.y += num > line.lon ? line.pos1.y : line.pos2.y;
		num -= num > line.lon ? line.lon : 0;
	}
}

void		draw_line(t_mlx *fdf, t_vector start, t_vector end)
{
	t_line	line;

	line.diff.x = end.x - start.x;
	line.diff.y = end.y - start.y;
	line.pos1.x = line.diff.x <= 0 ? -1 : 1;
	line.pos1.y = line.diff.y <= 0 ? -1 : 1;
	line.lon = abs(line.diff.x) > abs(line.diff.y) ?
		abs(line.diff.x) : abs(line.diff.y);
	line.sho = abs(line.diff.x) > abs(line.diff.y) ?
		abs(line.diff.y) : abs(line.diff.x);
	line.pos2.x = abs(line.diff.x) > abs(line.diff.y) ? line.pos1.x : 0;
	line.pos2.y = abs(line.diff.x) > abs(line.diff.y) ? 0 : line.pos1.y;
	compare(fdf, line, start, end);
}
