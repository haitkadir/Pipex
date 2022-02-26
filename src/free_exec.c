#include "pipex.h"

static void free_2d(char **tow_d_arr)
{
	int i;

	i = 0;
	while (tow_d_arr[i])
		free(tow_d_arr[i++]);
	free(tow_d_arr);
}

void free_exec(t_exec *exec)
{
	int i;
	i = 0;
	if (exec->cmd_switchs1)
		free_2d(exec->cmd_switchs1);
	i = 0;
	if (exec->cmd_switchs2)
		free_2d(exec->cmd_switchs2);
	if (exec->full_cmd1)
		free(exec->full_cmd1);
	if (exec->full_cmd2)
		free(exec->full_cmd2);
	if (exec->infile)
		close(exec->infile);
	if (exec->outfile)
		close(exec->outfile);
	if (exec)
		free(exec);
}