#include "../pipex.h"

static void free_paths(char **paths)
{
    int i;

    i = 0;
    if (paths)
    {
        while(paths[i])
            free(paths[i++]);
        free(paths);
    }
}

static void check_file(t_exec *exec, char *infile)
{
    if(access(infile, F_OK) == 0)
        exec->infile = ft_strdup(infile);
    else
        exec->err = 9;
}

static char **get_paths(char **env)
{
	char *path;
    char **tmp_path;
    int i;

	path = NULL;
    tmp_path = NULL;
    i = 0;
	while (env[i])
	{
		path = ft_strnstr(env[i], "PATH", 5);
		if (path){
            return(ft_split(*&path + 5, ':'));
        }
        i++;
    }
    return (NULL);
}

static char *check_cmd(char **paths, char *cmd)
{
    char *tmp_cmd;
    char *full_cmd;
    int i;

    i = 0;
    tmp_cmd = ft_strjoin("/", cmd);
    while (paths[i])
    {
        full_cmd = ft_strjoin(paths[i], tmp_cmd);
        if (access (full_cmd, F_OK) == 0)
            break;
        if (full_cmd)
            free(full_cmd);
        full_cmd = NULL;
        i++;
    }
    if (tmp_cmd)
        free(tmp_cmd);
    if (access (full_cmd, F_OK) == 0)
        return (full_cmd);
    return (NULL);
}

t_exec parsing(char **env, char **av)
{
    t_exec exec;
    char **paths;

    ft_bzero(&exec, sizeof(t_exec));
    paths = NULL;
    if (!(paths = get_paths(env)))
        exec.err = 1;
    exec.cmd_switchs1 = ft_split(av[2], ' ');
    if (!(exec.full_cmd1 =  check_cmd(paths, exec.cmd_switchs1[0])))
        exec.err = 1;
    check_file(&exec, av[1]);

    exec.cmd_switchs2 = ft_split(av[3], ' ');
    if (!(exec.full_cmd2 =  check_cmd(paths, exec.cmd_switchs2[0])))
        exec.err = 1;
    if (paths)
        free_paths(paths);
    exec.outfile = ft_strdup(av[4]);
    if (exec.err)
    {
        ft_printf("\n ------------------DEBUG-------------err(%d)-----\n", exec.err);
        free_exec(&exec);
        exit(0);
    }
    return (exec);
}
