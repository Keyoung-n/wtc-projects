# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knage <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 15:03:57 by knage             #+#    #+#              #
#    Updated: 2016/07/23 14:51:38 by knage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	lem-in

SRC =	lem_in.c extract.c error_tests.c support.c convert.c \
		algo.c init.c print.c libft/libft.a

all: $(NAME)

$(NAME):
	@echo "\033[0;35mcompiling libft..."
	@make re -C libft
	@echo "\033[0;36mcompiling program..."
	@clang -o $(NAME) -Wall -Werror -Wextra $(SRC)
	@echo "\033[0;32mdone! :D"

clean:
	@make clean -C libft

fclean:	clean
	@make fclean -C libft
	@rm -rf $(NAME)

re:	fclean 
	@make

me:
	@rm -rf author
	@echo knage > author
