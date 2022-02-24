#include "pipex.h"

static void first_process(t_exec exec, int fd[2])
{
	int infilefd;
	
	close(fd[0]);
	infilefd = open(exec.infile, O_RDONLY);

	dup2(infilefd, 0);
	close(infilefd);
	dup2(fd[1], 2);
	close(fd[1]);
	execve(exec.full_cmd1, exec.cmd_switchs1, NULL);
}

static void secund_process(t_exec exec, int fd[2])
{
	int infilefd;
	
	close(fd[1]);
	ft_printf("\n---------- DEBUG ---------\n");
	infilefd = open(exec.outfile, O_RDONLY|O_CREAT, 0777);
	dup2(fd[0], 0);
	close(fd[1]);
	dup2(infilefd, 1);
	execve(exec.full_cmd1, exec.cmd_switchs2, NULL);
}

int	main(int ac, char **av, char **env){
	int	fd[2];
	int	pid1;
	int	pid2;
	t_exec exec;

	ft_bzero(&exec, sizeof(t_exec));
	if (ac == 5)
	{
		exec = parsing(env, av);

		if (pipe(fd) == -1)
			return (1);
		if ((pid1 = fork()) == -1)
			return (2);
		if (pid1 == 0)
			first_process(exec, fd);
		pid2 = fork();
		if (pid1 == 0)
			secund_process(exec, fd);
		
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}
