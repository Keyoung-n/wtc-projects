# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcowle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/10 14:07:55 by kcowle            #+#    #+#              #
#    Updated: 2016/08/01 15:25:02 by smahomed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

LIB = libft/libft.a

CC = gcc -g

SRC = tricks.c non_canonical1.c non_canonical2.c non_canonical.c\
	  free.c signals.c history.c fdfuncs.c pipes.c new.c main.c\
	  extras.c func.c help.c echo.c non_canonical3.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $(NAME) $(SRC) libft/libft.a -ltermcap

clean:
	@make clean -C libft/
	@rm $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm $(NAME)

re: fclean all
