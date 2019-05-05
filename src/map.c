/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 16:39:44 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 15:53:00 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

static	int		get_content_file(int fd, t_list **lst, t_map **map)
{
	t_list		*temp;
	char		*line;

	line = NULL;
	(*map)->height = 0;
	while (get_next_line(fd, &line))
	{
		(*map)->height += 1;
		if (!(temp = ft_lstnew(line, ft_strlen(line))))
			return (0);
		ft_lstadd(lst, temp);
		ft_strdel(&line);
	}
	ft_lstrev(lst);
	return (1);
}

static void		add_param_vectors(t_map **map)
{
	int			l;
	int			c;
	t_pos		mid_pos;

	l = -1;
	mid_pos.y = (*map)->height / 2;
	mid_pos.x = (*map)->width / 2;
	(*map)->start.x = WIN_WIDTH / 2 + (*map)->move.x;
	(*map)->start.y = WIN_HEIGHT / 2 + (*map)->move.y;
	get_depth(map);
	while (++l < (*map)->height && (c = -1))
		while (++c < (*map)->width)
		{
			(*map)->vectors[l][c].x = (*map)->start.x + ((c - mid_pos.x) *
			(*map)->gap.x) + ((-2 * (*map)->gap.y) * (l - mid_pos.y));
			(*map)->vectors[l][c].y = ((*map)->start.y + ((c - mid_pos.x) *
			(*map)->gap.y) + ((*map)->gap.y * (l - mid_pos.y))) +
			(-(*map)->gap.z * (*map)->vectors[l][c].z);
			get_point_color(&(*map)->vectors[l][c], (*map));
		}
}

static t_vector	*get_vectors(char *line)
{
	char		**test;
	int			i;
	t_vector	*vector;

	i = -1;
	CHECK_NULL((test = ft_strsplit(line, ' ')));
	CHECK_NULL((vector = malloc(sizeof(t_vector) * ft_countwords(line, ' '))));
	while (test[++i])
	{
		if (!check_value(test[i]))
			return (NULL);
		vector[i].z = ft_atoi(test[i]);
		free(test[i]);
	}
	free(test);
	return (vector);
}

t_map			*get_map(int fd)
{
	int			i;
	t_list		*lst;
	t_map		*map;

	lst = NULL;
	CHECK_NULL((map = ft_memalloc(sizeof(t_map))));
	CHECK_NULL((get_content_file(fd, &lst, &map)));
	map->width = ft_countwords(lst->content, ' ');
	CHECK_NULL((map->vectors = ft_memalloc(sizeof(t_vector *) *
					map->height)));
	get_gap(&(*map));
	i = -1;
	while (lst)
	{
		if ((int)ft_countwords(lst->content, ' ') != map->width)
			return (NULL);
		CHECK_NULL((map->vectors[++i] = get_vectors(lst->content)));
		free(lst->content);
		free(lst);
		lst = lst->next;
	}
	return (map);
}

void			draw_window(t_mlx *fdf)
{
	int			l;
	int			c;

	reset_image(fdf->img);
	add_param_vectors(&fdf->map);
	l = -1;
	while (++l < fdf->map->height && (c = -1))
		while (++c < fdf->map->width)
		{
			if (c < fdf->map->width - 1)
				draw_line(fdf, fdf->map->vectors[l][c],
					fdf->map->vectors[l][c + 1]);
			if (l < fdf->map->height - 1)
				draw_line(fdf, fdf->map->vectors[l][c],
					fdf->map->vectors[l + 1][c]);
		}
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->img, 0, 0);
}
