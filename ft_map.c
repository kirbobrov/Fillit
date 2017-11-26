/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:58:18 by kbobrov           #+#    #+#             */
/*   Updated: 2017/01/11 16:41:46 by kzahreba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clearmap(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		map[i++] = NULL;
	}
	free(map);
}

char	**ft_map(int size)
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	map = 0;
	map = (char **)malloc(sizeof(char *) * size + 1);
	if (!map)
		return (NULL);
	while (x < size)
	{
		map[x] = (char*)malloc(sizeof(char) * size + 1);
		if (!map[x])
			return (NULL);
		y = 0;
		while (y < size)
		{
			map[x][y] = '.';
			y++;
		}
		map[x][y] = '\0';
		x++;
	}
	map[x] = NULL;
	return (map);
}
