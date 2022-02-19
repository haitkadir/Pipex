#include "pipex.h"

char **get_path(char *env)
{
	char *path;

	path = NULL;
	while (env)
	{
		path = ft_strnstr(env++, "PATH", 5);
		if (path)
			return (ft_split(*&path + 5, ':'));
	}
	return (0);
}

int	main(int ac, char **av, char **env){
	// int	fd[2];
	// int	pid1;
	// int	pid2;

	// if (pipe(fd) == -1)
	// 	return (1);
	// pid1 = fork();
	// if (pid1 == -1)
	// 	return (2);
	// if (pid1 == 0)
	// {
	// 	close(fd[0]);
	// }
	ft_printf("%d %s\n", ac, av[0]);

	ft_printf("paht: %s", get_path(*env)[0]);
	return (0);
}
