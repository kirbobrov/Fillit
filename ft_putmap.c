/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 20:24:53 by kbobrov           #+#    #+#             */
/*   Updated: 2017/01/11 16:54:42 by kzahreba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_putendl(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void			ft_putmap(char **map, int size)
{
	int	i;

	i = 0;
	if (map)
	{
		while (i < size)
		{
			ft_putendl(map[i]);
			i++;
		}
	}
}
