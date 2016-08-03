# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knage <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/11 17:36:02 by knage             #+#    #+#              #
#    Updated: 2016/07/16 15:27:25 by knage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC = ft_select.c list.c terminal.c signals.c support.c libft/libft.a

all: $(NAME)

$(NAME):
	@echo "Making libft..."
	@make re -C libft
	@echo "Compiling program..."
	@clang -o $(NAME) -ltermcap -Wall -Werror -Wextra $(SRC)
	@echo "Done! :D"

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean 
	@make

me:
	@echo "knage" > author
