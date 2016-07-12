# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knage <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/11 17:36:02 by knage             #+#    #+#              #
#    Updated: 2016/07/12 11:30:59 by knage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC = ft_select.c libft/libft.a

all: $(NAME)

$(NAME):
	@make re -C libft
	@clang -o $(NAME) -ltermcap -Wall -Werror -Wextra $(SRC)

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean 
	@make
