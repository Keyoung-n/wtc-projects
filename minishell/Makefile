# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knage <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 07:26:46 by knage             #+#    #+#              #
#    Updated: 2016/07/04 08:23:29 by knage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = minishell.c commands.c libft/libft.a

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

