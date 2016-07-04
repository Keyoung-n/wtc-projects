NAME = fdf

SRC = main.c draw.c libft/libft.a support.c

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft/
	@cc $(CFLAGS) -o $(NAME) $(SRC) -lmlx -framework OpenGL -framework AppKit
clean:
	@make -C libft/ clean

fclean:	clean
	@make -C libft/ fclean
	@rm -rf fdf

re: fclean all
