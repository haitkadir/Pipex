#include "pipex.h"



int	main(int ac, char **av, char **env){
	// int	fd[2];
	// int	pid1;
	// int	pid2;
	t_exec exec;

	ft_bzero(&exec, sizeof(t_exec));
	if (ac == 5)
	{
		// ft_printf("%d %s\n", ac, av[0]);
		// ft_printf("Result: %s", cmd_iterator(env, av[2])[0]);
		ft_printf("before: %s\n", exec.cmd_switchs1);
		exec = parsing(env, av);
		execve(exec.full_cmd1, exec.cmd_switchs1, NULL);
		ft_printf("after\n");
	}
	// if (pipe(fd) == -1)
	// 	return (1);
	// pid1 = fork();
	// if (pid1 == -1)
	// 	return (2);
	// if (pid1 == 0)
	// {
	// 	close(fd[0]);
	// }
	return (0);
}
