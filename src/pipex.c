/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:27:34 by haitkadi          #+#    #+#             */
/*   Updated: 2022/02/26 22:27:37 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	free_and_exit(t_exec *exec)
{
	error(exec->err);
	free_exec(exec);
	exit(0);
}

static	void	first_process(t_exec *exec, int fd[2])
{
	close(fd[0]);
	if (dup2(exec->infile, STDIN_FILENO) == -1)
		free_and_exit(exec);
	close(exec->infile);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		free_and_exit(exec);
	close(fd[1]);
	if (execve(exec->full_cmd1, exec->cmd_switchs1, NULL) == -1)
		free_and_exit(exec);
}

static	void	second_process(t_exec *exec, int fd[2])
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		free_and_exit(exec);
	if (dup2(exec->outfile, STDOUT_FILENO) == -1)
		free_and_exit(exec);
	close(exec->outfile);
	close(fd[0]);
	if (execve(exec->full_cmd2, exec->cmd_switchs2, NULL) == -1)
		free_and_exit(exec);
}

static	void	the_recipe(t_exec *exec)
{
	int		fd[2];
	int		pid1;
	int		pid2;

	if ((exec)->err)
		free_and_exit(exec);
	if (pipe(fd) == -1)
		free_and_exit(exec);
	pid1 = fork();
	if (pid1 == -1)
		free_and_exit(exec);
	if (pid1 == 0)
		first_process(exec, fd);
	pid2 = fork();
	if (pid2 == 0)
		second_process(exec, fd);
	else if (pid2 == -1)
		free_and_exit(exec);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free_and_exit(exec);
}

int	main(int ac, char **av, char **env)
{
	t_exec	*exec;

	if (ac == 5)
	{
		exec = parsing(env, av);
		the_recipe(exec);
	}
	else
		error(5);
	return (0);
}
