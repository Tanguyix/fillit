# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twalpert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 16:25:40 by twalpert          #+#    #+#              #
#    Updated: 2018/04/19 10:42:33 by twalpert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OBJ = main.o fillall.o

HEAD = ft_fillit.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

.PHONY: clean fclean all re

$(NAME): $(OBJ) $(HEAD)
	$(CC) -o $@ $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
