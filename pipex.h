#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "./assets/ft_printf/ft_printf.h"
# include "./assets/libft/libft.h"

/*------------------- MAIN FUNCTION ---------------------*/
char **cmd_iterator(char *env, char *cmd);

#endif