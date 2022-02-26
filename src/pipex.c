#include "pipex.h"

static	void	free_and_exit(t_exec **exec)
{
	error((**exec).err);
	free_exec(&*exec);
	exit(0);
}

static void first_process(t_exec exec, int fd[2])
{
	close(fd[0]);
	dup2(exec.infile, STDIN_FILENO);
	close(exec.infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve(exec.full_cmd1, exec.cmd_switchs1, NULL);
}

static void second_process(t_exec exec, int fd[2])
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(exec.outfile, STDOUT_FILENO);
	close(fd[0]);
	execve(exec.full_cmd2, exec.cmd_switchs2, NULL);
}

static void the_recipe(t_exec **exec)
{
	int		fd[2];
	int		pid1;
	int		pid2;

	if ((**exec).err || 1)
		free_and_exit(&*exec);
	if (pipe(fd) == -1)
		free_and_exit(exec);
	if ((pid1 = fork()) == -1)
		free_and_exit(exec);
	if (pid1 == 0)
		first_process(**exec, fd);
	if ((pid2 = fork()) == 0)
		second_process(**exec, fd);
	else if (pid2 == -1)
		free_and_exit(exec);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	t_exec	*exec;

	ft_bzero(&exec, sizeof(t_exec));
	if (ac == 5)
	{
		*exec = parsing(env, av);
		the_recipe(&exec);
	}
	else
		error(5);
	return (0);
}
