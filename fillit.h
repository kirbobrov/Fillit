/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzahreba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:24:16 by kzahreba          #+#    #+#             */
/*   Updated: 2017/01/11 16:37:36 by kzahreba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 545
# define XYS XYS0 && XYS1 && XYS2 && XYS3
# define XYS0 i + list->y[0] < size && j + list->x[0] < size
# define XYS1 i + list->y[1] < size && j + list->x[1] < size
# define XYS2 i + list->y[2] < size && j + list->x[2] < size
# define XYS3 i + list->y[3] < size && j + list->x[3] < size
# define XYN XYN0 && XYN1 && XYN2 && XYN3
# define XYN0 i + list->y[0] >= 0  && j + list->x[0] >= 0
# define XYN1 i + list->y[1] >= 0  && j + list->x[1] >= 0
# define XYN2 i + list->y[2] >= 0  && j + list->x[2] >= 0
# define XYN3 i + list->y[3] >= 0  && j + list->x[3] >= 0
# define XYP XYP0 && XYP1 && XYP2 && XYP3
# define XYP0 map[i + list->y[0]][j + list->x[0]] == '.'
# define XYP1 map[i + list->y[1]][j + list->x[1]] == '.'
# define XYP2 map[i + list->y[2]][j + list->x[2]] == '.'
# define XYP3 map[i + list->y[3]][j + list->x[3]] == '.'

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_tetr
{
	int				x[4];
	int				y[4];
	char			c;
	struct s_tetr	*next;
}					t_tetr;

int					ft_valid(char *str);
void				ft_puterror(void);
int					ft_stlen(char *str);
t_tetr				*ft_createlist(char *str);
void				ft_putmap(char **map, int i);
char				**ft_map(int n);
void				ft_fillmap(t_tetr *list, int size);
void				ft_clearmap(char **map, int i);

#endif
