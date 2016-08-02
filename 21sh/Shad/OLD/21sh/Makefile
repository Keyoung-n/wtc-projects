# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcowle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/10 14:07:55 by kcowle            #+#    #+#              #
#    Updated: 2016/07/31 15:00:05 by knage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

LIB = libft/libft.a

CC = gcc -g

SRC = history.c fdfuncs.c pipes.c new.c main.c extras.c func.c help.c\
	  echo.c non_canonical.c non_canonical1.c tricks.c

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
