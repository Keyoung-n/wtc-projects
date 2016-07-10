# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knage <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/10 13:40:37 by knage             #+#    #+#              #
#    Updated: 2016/07/10 14:02:22 by knage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= minishell

LIB= includes/libft.a

CC=clang -Wall -Werror -Wextra

SRC= main.c extras.c func.c help.c echo.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C includes/
	@$(CC) -o $(NAME) $(SRC) includes/libft.a

clean:
	@make clean -C includes/
	@rm $(OBJ)

fclean: clean
	@make fclean -C includes/
	@rm $(NAME)

re: fclean all
