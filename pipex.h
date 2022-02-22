#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "./assets/ft_printf/ft_printf.h"
# include "./assets/libft/libft.h"
/*------------------- STRUCTS ---------------------------*/
typedef struct s_exec {
				char **cmd_split;
				char  *cmd_path;
				int    file;
				int    err;
}              t_exec;

typedef struct s_pipe {
				int    write_fd;
				int    pipe_fd[2];
				pid_t  pid[2];
				int    status;
}              t_pipe;
/*------------------- PARSING FUNCTIONS ---------------------*/
t_exec parsing(char **env, char **av);

#endif