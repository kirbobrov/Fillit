/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzahreba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:16:20 by kzahreba          #+#    #+#             */
/*   Updated: 2017/01/10 18:20:49 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*str;
	char	buf;
	int		i;
	t_tetr	*tmp;

	i = 0;
	if (2 != argc)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_puterror();
	str = (char *)malloc(BUF_SIZE);
	while ((read(fd, &buf, 1)) > 0)
		str[i++] = buf;
	str[i] = '\0';
	close(fd);
	i = ft_valid(str);
	tmp = ft_createlist(str);
	ft_fillmap(tmp, i);
	return (0);
}
