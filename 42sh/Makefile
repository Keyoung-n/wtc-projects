# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcowle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/07 15:59:15 by kcowle            #+#    #+#              #
#    Updated: 2016/08/30 07:24:07 by knage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

CC = clang

SRC =	file_arf.c			\
		cut_copy_paste.c	\
		cut_copy_paste_key.c\
		non_canonical1.c	\
	  	non_canonical2.c	\
		non_canonical3.c    \
		non_canonical4.c    \
	  	non_canonical.c		\
	  	free.c				\
	   	signals.c			\
	   	history.c			\
	   	fdfuncs.c			\
	   	pipes.c				\
	   	new.c				\
		main.c				\
	  	extras.c			\
	   	func.c				\
	   	help.c				\
	   	echo.c				\
	   	quote.c				\
	   	builtin.c			\
	   	shell.c				\
		ft_excve.c			\
		redirection.c		\
		vars.c				\
		variables.c			\
		key_hook.c			\
		get_str.c			\
		libft/libft.a		\

all: $(NAME)

$(NAME):
	@echo "compiling libft..."
	@make re -C libft/
	@echo "compiling program..."
	@$(CC) -o $(NAME) $(SRC) -ltermcap
	@echo "done! :D"

clean:
	@make clean -C libft/

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all

run: re 
	@echo "running program"
	./$(NAME)
