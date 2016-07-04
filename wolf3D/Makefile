# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knage <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/24 12:31:51 by knage             #+#    #+#              #
#    Updated: 2016/06/24 12:38:45 by knage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft = libft/libft.a
CC = clang
NAME= Wolf3D
SRC = draw_to_image.c get_map.c extras.c main.c raycastalgo.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling library..."
	@make re -C libft/
	@echo "Compiling Program..."
	@$(CC) -o $(NAME) $(OBJ) $(libft) -lmlx -framework OpenGL -framework AppKit
	@echo "Finished! :D"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
