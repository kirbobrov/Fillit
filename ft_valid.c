/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 19:32:55 by kbobrov           #+#    #+#             */
/*   Updated: 2017/01/11 16:09:53 by kzahreba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_valtetrimino(char *str, int i, int n)
{
	int d;

	d = 0;
	if (n - 1 >= 0 && str[i - 1] == '#')
		d++;
	if (n + 1 <= 18 && str[i + 1] == '#')
		d++;
	if (n - 5 >= 0 && str[i - 5] == '#')
		d++;
	if (n + 5 <= 18 && str[i + 5] == '#')
		d++;
	return (d);
}

static void		ft_valsection1(char *str)
{
	int i;
	int ct;
	int n;
	int k;

	i = 0;
	while (str[i])
	{
		n = 0;
		ct = 0;
		k = 0;
		while (n < 21 && str[i + n])
		{
			if (str[i + n] == '.')
				k++;
			if (str[i + n] == '#')
				ct++;
			n++;
		}
		if (k != 12 || ct != 4)
		{
			ft_puterror();
		}
		i = i + 21;
	}
}

static void		ft_valsection2(char *str)
{
	int	i;
	int	n;
	int d;

	i = 0;
	while (str[i])
	{
		n = 0;
		d = 0;
		while (n < 21 && str[i + n])
		{
			if (str[i + 4] != '\n' && str[i + 9] != '\n')
				ft_puterror();
			if (str[i + 14] != '\n' && str[i + 19] != '\n')
				ft_puterror();
			if (str[i + 20] != '\n' && str[i + 20] != '\0')
				ft_puterror();
			if (str[i + n] == '#')
				d += ft_valtetrimino(str, (i + n), n);
			n++;
		}
		if (d != 6 && d != 8)
			ft_puterror();
		i = i + 21;
	}
}

int				ft_valid(char *str)
{
	int i;
	int n;
	int k;

	i = 0;
	k = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '#' && str[i] != '.')
			ft_puterror();
		if (str[i] == '#')
			n++;
		i++;
	}
	if (i > 545 || (i + 1) % 21 != 0)
		ft_puterror();
	ft_valsection1(str);
	ft_valsection2(str);
	while (k * k < n)
		k++;
	return (k);
}
