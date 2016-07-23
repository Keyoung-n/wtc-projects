# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knage <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 15:03:57 by knage             #+#    #+#              #
#    Updated: 2016/07/23 11:35:04 by knage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRC =	lem_in.c extract.c error_tests.c support.c convert.c \
	algo.c init.c print.c libft/libft.a

all: $(NAME)

$(NAME):
	@make re -C libft
	@clang -o $(NAME) -Wall -Werror -Wextra $(SRC)

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean 
	@make
