#include "pipex.h"



int	main(int ac, char **av, char **env){
	// int	fd[2];
	// int	pid1;
	// int	pid2;
	if (ac == 5)
	{
		ft_printf("%d %s\n", ac, av[0]);
		ft_printf("paht: %s", cmd_iterator(*env, av[2])[0]);
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
