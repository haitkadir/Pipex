NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = ./src/pipex.c ./src/parsing.c ./src/free_exec.c ./src/errors.c

all: $(NAME)

$(NAME): compile_assets
	$(CC) $(CFLAGS) -L ./assets/libft/ -lft $(SRC) -o $(NAME)

compile_assets:
	make -C ./assets/libft/

clean:
	make clean -C ./assets/libft/

fclean:
	make fclean -C ./assets/libft/

re: fclean all