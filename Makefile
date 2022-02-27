# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 22:28:14 by haitkadi          #+#    #+#              #
#    Updated: 2022/02/26 22:28:19 by haitkadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Reset
Color_Off='\033[0m'       # Text Reset
# Regular Colors
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
BYellow='\033[1;33m'      # Yellow

NAME = pipex
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
ASSETS = assets/ft_bzero.c assets/ft_calloc.c assets/ft_putstr_fd.c \
		assets/ft_split.c assets/ft_strjoin.c assets/ft_strlen.c \
		assets/ft_strnstr.c assets/ft_strtrim.c assets/ft_substr.c \
		assets/ft_strdup.c
SRC = ./src/pipex.c ./src/parsing.c ./src/free_exec.c ./src/errors.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC) $(ASSETS)
	@$(CC) $(CFLAGS) $(SRC) $(ASSETS) -o $(NAME)
	@echo $(Green)"Compiled successfuly"$(Color_Off)
	@echo $(BYellow)"Usage: ./pipex infile cmd1 cmd2 outfile"$(Color_Off)

clean:
	@rm -f pipex
	@echo $(Red)"Cleand successfuly"$(Color_Off)

fclean: clean

re: fclean all