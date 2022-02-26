#include "pipex.h"


void free_exec(t_exec **exec)
{
    int i;
    i = 0;
    if((**exec).cmd_switchs1)
    {
        while((**exec).cmd_switchs1[i])
            free((**exec).cmd_switchs1[i++]);
        free((**exec).cmd_switchs1);
    }
    i = 0;
    if((**exec).cmd_switchs2)
    {
    // write(1, "--------debug--------\n", 24);
        while((**exec).cmd_switchs2[i])
            free((**exec).cmd_switchs2[i++]);
        free((**exec).cmd_switchs2);
    }
    if((**exec).full_cmd1)
        free((**exec).full_cmd1);
    if((**exec).full_cmd2)
        free((**exec).full_cmd2);
    if((**exec).infile)
        close((**exec).infile);
    if((**exec).outfile)
        close((**exec).outfile);
}