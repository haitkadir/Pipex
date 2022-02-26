/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:27:45 by haitkadi          #+#    #+#             */
/*   Updated: 2022/02/26 22:27:48 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

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
/*------------------- ASSETS FUNCTIONS ---------------------*/
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

/*------------------- PARSING FUNCTIONS ---------------------*/
t_exec	*parsing(char **env, char **av);
/*------------------- PRINT ERROR FUNCTIONS -----------------*/
void	error(int err);
void	exit_err(void);
/*----------------- FREE MEMORY FUNCTIONS -------------------*/
void	free_exec(t_exec *exec);

#endif
