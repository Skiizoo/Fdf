/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnequ.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 15:27:29 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 15:27:31 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	return (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
}