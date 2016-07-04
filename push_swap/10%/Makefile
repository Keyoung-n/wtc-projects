# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knage <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/24 06:52:21 by knage             #+#    #+#              #
#    Updated: 2016/07/02 15:00:03 by knage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c commands.c support.c algo.c stack_functions.c libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "loading..."
	@echo "compiling library..."
	@make re -C libft
	@echo "compiling program..."
	@gcc -o $(NAME) $(FLAGS) $(SRC)
	@echo "Done. :D"

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean
	@make
