# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knage <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/19 14:26:39 by knage             #+#    #+#              #
#    Updated: 2016/06/19 14:26:41 by knage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c sort.c support.c flags.c extra.c includes/libft.a

all: $(NAME)

$(NAME):
	@make re -C includes
	@gcc -o $(NAME) -Wall -Werror -Wextra $(SRC)

clean:
	@make clean -C includes

fclean: clean
	@make fclean -C includes
	@rm -rf $(NAME)

re: fclean 
	@make
