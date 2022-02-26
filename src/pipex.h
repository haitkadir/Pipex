#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../assets/libft/libft.h"

/*------------------ SHORTCUTS --------------------------*/

/*------------------- STRUCTS ---------------------------*/
typedef struct s_exec
{
	char	**cmd_switchs1;
	char	*full_cmd1;
	int		infile;
	char	**cmd_switchs2;
	char	*full_cmd2;
	int		outfile;
	int		err;
}	t_exec;

/*------------------- PARSING FUNCTIONS ---------------------*/
t_exec	parsing(char **env, char **av);
/*------------------- PRINT ERROR FUNCTIONS -----------------*/
void	error(int err);
/*----------------- FREE MEMORY FUNCTIONS -------------------*/
void	free_exec(t_exec **exec);

#endif