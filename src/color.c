/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 18:01:53 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 17:22:21 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

int			get_color(int c1, int c2, double p)
{
	int		r;
	int		g;
	int		b;

	r = (((c1 >> 16) & 0xFF) + (((c2 >> 16) & 0xFF) - ((c1 >> 16) & 0xFF)) * p);
	g = (((c1 >> 8) & 0xFF) + (((c2 >> 8) & 0xFF) - ((c1 >> 8) & 0xFF)) * p);
	b = ((c1 & 0xFF) + ((c2 & 0xFF) - (c1 & 0xFF)) * p);
	return (r << 16 | g << 8 | b);
}

void		get_point_color(t_vector *v, t_map *map)
{
	double	p;

	p = 100 * (v->z / map->max);
	if (p >= 70)
		v->color = 0xFFFFFF;
	if (p >= 25 && p < 70)
		v->color = get_color(0x592B00, 0x261200, (p - 25) / 45);
	if ((p > 0 && p < 25))
		v->color = get_color(0x019E1C, 0x003D0B, p / 25);
	if (p <= 0)
		v->color = get_color(0x00000F, 0x0000B5, ((p - map->min) / -map->min)
		- 0.5);
}
