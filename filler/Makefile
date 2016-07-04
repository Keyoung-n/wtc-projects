# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knage <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/12 16:54:28 by knage             #+#    #+#              #
#    Updated: 2016/06/12 16:54:30 by knage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = main.c get.c insert.c support.c algo.c libft/libft.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(CFLAGS) -o $(NAME) $(SRC)
clean:
	@make -C libft/ clean

fclean:	clean
	@make -C libft/ fclean
	@rm -rf $(NAME)

re: fclean all
