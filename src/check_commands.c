#include "../pipex.h"

static void get_cmd_path(char **cmd, char **path, t_exec **exec)
{
    char *tmp_cmd;
    int i;

    i = 0;
    tmp_cmd = ft_strjoin("/", cmd[0]);
    while (path[i])
    {
        (**exec).cmd_path = ft_strjoin(path[i], tmp_cmd);
        if (access ((**exec).cmd_path, F_OK) == 0)
        {
            (**exec).cmd_split = ft_split(*cmd, ' ');
            break;
        }
        if ((**exec).cmd_path)
            free((**exec).cmd_path);
        (**exec).cmd_path = NULL;
        i++;
    }
    if (access ((**exec).cmd_path, F_OK) == 0)
    {
        (**exec).err = 1;
        (**exec).cmd_path = NULL;
        (**exec).cmd_split = NULL;
    }
}

static void check_cmd(char **env, char *cmd, t_exec *exec)
{
	char *path;
    char **tmp_path;
    char **tmp_cmd;
    int i;

	path = NULL;
    tmp_path = NULL;
    tmp_cmd = NULL;
    i = 0;
	while (env[i])
	{
		path = ft_strnstr(env[i], "PATH", 5);
		if (path){
            tmp_path = ft_split(*&path + 5, ':');
            tmp_cmd = ft_split(cmd, ' ');
            get_cmd_path(tmp_cmd, tmp_path, &exec);
            if (tmp_path)
                free(tmp_path);
            if (tmp_cmd)
                free(tmp_cmd);
        }
        i++;
    }
}

static void check_file(t_exec *exec, char *infile)
{
    if(access(infile, F_OK) == 0)
    {
        exec->err = 2;
    }
}

t_exec parsing(char **env, char **av)
{
    t_exec exec;

    ft_bzero(&exec, sizeof(t_exec));
    check_cmd(env, av[1], &exec);
    check_file(&exec, av[2]);
}
