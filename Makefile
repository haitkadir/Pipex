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

NAME = pipex
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
ASSETS = assets/ft_bzero.c assets/ft_calloc.c assets/ft_putstr_fd.c \
		assets/ft_split.c assets/ft_strjoin.c assets/ft_strlen.c \
		assets/ft_strnstr.c assets/ft_strtrim.c assets/ft_substr.c \
		assets/ft_strdup.c
SRC = ./src/pipex.c ./src/parsing.c ./src/free_exec.c ./src/errors.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(ASSETS) -o $(NAME)

clean:
	rm -f pipex

fclean: clean

re: fclean all
