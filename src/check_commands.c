#include "../pipex.h"

static char **get_cmd_path(char **cmd, char **path)
{
    char **args;
    char *full_cmd;

    full_cmd = NULL;
    //need to allocate tow bytes in args variable here ok
    {
        full_cmd = ft_strjoin(*path, cmd[0]);
        if (access (full_cmd, F_OK) == 0)
        {
            args[0] = full_cmd;
            args[1] = *ft_split(*cmd, ' ');
            return (args);
        }
    }
    return (0);
}

char **cmd_iterator(char *env, char *cmd)
{
	char *path;
    char **args;
    char **tmp_path;
    char **tmp_cmd;

	path = NULL;
    args = NULL;
    tmp_path = NULL;
    tmp_cmd = NULL;
	while (env)
	{
		path = ft_strnstr(env++, "PATH", 5);
		if (path){
            tmp_path = ft_split(*&path + 5, ':');
            tmp_cmd = ft_split(cmd, ' ');
            args = get_cmd_path(tmp_cmd, tmp_path);
            if (tmp_path)
                free(tmp_path);
            if (tmp_cmd)
                free(tmp_cmd);
            return (*&args);
        }
    }
	return (NULL);
}
