# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzahreba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/18 15:27:11 by kzahreba          #+#    #+#              #
#    Updated: 2017/01/09 17:48:18 by kzahreba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLAGS = -Wall -Wextra -Werror
FT = main.c ft_puterror.c ft_valid.c ft_createlist.c ft_stlen.c ft_map.c ft_putmap.c ft_fillmap.c
CC = gcc
OBJ = $(FT:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

