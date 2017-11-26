/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzahreba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:42:15 by kzahreba          #+#    #+#             */
/*   Updated: 2017/01/11 15:53:52 by kzahreba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_mkstruct(t_tetr *new, char **str)
{
	int a;
	int b;
	int i;
	int j;
	int n;

	i = -1;
	n = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (str[i][j] == '#')
			{
				n++;
				if (n == 1)
				{
					a = j;
					b = i;
				}
				new->x[n - 1] = j - a;
				new->y[n - 1] = i - b;
			}
	}
}

static t_tetr	*ft_tetrnew(char **str, char a)
{
	t_tetr	*figure;
	int		j;
	int		ct;

	j = 0;
	ct = 0;
	figure = (t_tetr*)malloc(sizeof(t_tetr));
	if (!figure)
		return (NULL);
	if (str)
	{
		ft_mkstruct(figure, str);
		figure->c = a;
		figure->next = NULL;
	}
	return (figure);
}

static t_tetr	*ft_addelem(char *str, int n, char a)
{
	char	**figure;
	int		i;
	int		j;
	t_tetr	*tmp;

	i = 0;
	if (!(figure = (char **)malloc(sizeof(char*) * 5)))
		return (NULL);
	while (i < 4)
	{
		j = 0;
		if (!(figure[i] = (char *)malloc(sizeof(char) * 5)))
			return (0);
		while (str[n] != '\n')
		{
			figure[i][j++] = str[n++];
			figure[i][j] = '\0';
		}
		n++;
		i++;
	}
	figure[i] = (NULL);
	tmp = ft_tetrnew(figure, a);
	return (tmp);
}

static void		ft_addback(t_tetr *list, t_tetr *new)
{
	t_tetr *tmp;

	tmp = list;
	if (list == NULL)
		list = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_tetr			*ft_createlist(char *str)
{
	int		n;
	int		k;
	t_tetr	*list;
	t_tetr	*tmp;
	char	a;

	n = 0;
	a = 'A';
	list = ft_addelem(str, 0, a);
	n = 21;
	a++;
	k = ft_stlen(str);
	while (n < k)
	{
		tmp = ft_addelem(str, n, a);
		ft_addback(list, tmp);
		n += 21;
		a++;
	}
	return (list);
}
