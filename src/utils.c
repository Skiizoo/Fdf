/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/20 18:08:55 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 15:53:07 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

void		get_depth(t_map **map)
{
	int		l;
	int		c;

	(*map)->min = INT_MAX;
	(*map)->max = INT_MIN;
	l = -1;
	while (++l < (*map)->height && (c = -1))
		while (++c < (*map)->width)
		{
			if ((*map)->vectors[l][c].z > (*map)->max)
				(*map)->max = (*map)->vectors[l][c].z;
			if ((*map)->vectors[l][c].z < (*map)->min)
				(*map)->min = (*map)->vectors[l][c].z;
		}
}

double		get_percent(double start, double now, double end)
{
	if (now == start)
		return (0);
	if (now == end)
		return (1);
	return ((now - start) / (end - start));
}

void		get_gap(t_map *map)
{
	map->gap.x = 30;
	map->gap.y = 20;
	map->gap.z = 3;
	while (map->width * (map->gap.x + map->gap.y) > WIN_WIDTH)
	{
		if (map->gap.z <= 0.10)
			return ;
		map->gap.x -= 0.5;
		map->gap.y -= 0.33;
		map->gap.z -= 0.05;
	}
}

int			check_value(char *str)
{
	if (*str && *str == '-')
		str++;
	while (*str)
		if (*str < '0' || *str++ > '9')
			return (0);
	return (1);
}

void		change_depth(t_map **map, int i)
{
	int		l;
	int		c;

	l = -1;
	while (++l < (*map)->height && (c = -1))
		while (++c < (*map)->width)
		{
			if (!i && (*map)->vectors[l][c].z)
				(*map)->vectors[l][c].z = -(*map)->vectors[l][c].z;
			else if (i == 1 && (*map)->vectors[l][c].z)
			{
				if ((*map)->vectors[l][c].z < 0)
					(*map)->vectors[l][c].z += 3;
				else
					(*map)->vectors[l][c].z -= 3;
			}
			else if (i == 2 && (*map)->vectors[l][c].z)
			{
				if ((*map)->vectors[l][c].z < 0)
					(*map)->vectors[l][c].z -= 3;
				else
					(*map)->vectors[l][c].z += 3;
			}
		}
}
