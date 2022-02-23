NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = pipex.c ./src/check_commands.c ./src/free_exec.c

all: $(NAME)

$(NAME): compile_assets
	$(CC) $(CFLAGS) -L ./assets/ft_printf/ -lftprintf -L ./assets/libft/ -lft $(SRC) -o $(NAME) -g

compile_assets:
	make -C ./assets/ft_printf/
	make -C ./assets/libft/

clean:
	make clean -C ./assets/ft_printf/
	make clean -C ./assets/libft/

fclean:
	make fclean -C ./assets/ft_printf/
	make fclean -C ./assets/libft/

re: fclean all