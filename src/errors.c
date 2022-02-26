/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:26:54 by haitkadi          #+#    #+#             */
/*   Updated: 2022/02/26 22:27:02 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(int err)
{
	if (err == 1)
		ft_putstr_fd(2, "\033[0;31mError: invalid \"infile\"\n\033[0m");
	else if (err == 2)
		ft_putstr_fd(2, "\033[0;31mError: invalid \"FIRST command\"\n\033[0m");
	else if (err == 3)
		ft_putstr_fd(2, "\033[0;31mError: invalid \"second command\"\n\033[0m");
	else if (err == 4)
		ft_putstr_fd(2, "\033[0;31mUknown error while opening\"outfile\"\n\033[0m");
	else if (err == 5)
	{
		ft_putstr_fd(2, "\033[0;31mError: \"bad arguments\"\n\033[0m");
		ft_putstr_fd(2, \
		"\033[0;32mUsage: ./pipex infile cmd1 cmd2 outfile\n\033[0m");
	}
	else if (err == 6)
		ft_putstr_fd(2, "\033[0;31mError: \"bad commands\"\n\033[0m");
	else if (err)
		ft_putstr_fd(2, "\033[0;31mUknown error happend\n\033[0m");
}

void	exit_err(void)
{
	ft_putstr_fd(2, "\033[0;31mUknown error happend\n\033[0m");
	exit(1);
}
