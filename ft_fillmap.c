/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzahreba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:43:45 by kzahreba          #+#    #+#             */
/*   Updated: 2017/01/11 16:36:23 by kzahreba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_puttetr(char **map, int x, int y, t_tetr *list)
{
	int n;

	n = 0;
	while (n < 4)
	{
		map[y + list->y[n]][x + list->x[n]] = list->c;
		n++;
	}
}

static void		ft_cleartetr(char **map, int x, int y, t_tetr *list)
{
	int n;

	n = 0;
	while (n < 4)
	{
		map[y + list->y[n]][x + list->x[n]] = '.';
		n++;
	}
}

static int		ft_createmap(char **map, t_tetr *list, int size)
{
	int i;
	int j;

	i = 0;
	if (list == 0)
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (XYS && XYN && XYP)
			{
				ft_puttetr(map, j, i, list);
				if (ft_createmap(map, list->next, size))
					return (1);
				else
					ft_cleartetr(map, j, i, list);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void			ft_fillmap(t_tetr *list, int size)
{
	char **map;

	map = ft_map(size);
	while (!(ft_createmap(map, list, size)))
	{
		ft_clearmap(map, size);
		size++;
		map = ft_map(size);
	}
	ft_putmap(map, size);
}
