#include "pipex.h"

void	error(int err)
{
	if (err == 1)
		write(2, "\033[0;31mError: invalid \"infile\"\n\033[0m", 32);
	else if (err == 2)
		write (2, "\033[0;31mError: invalid \"FIRST command\"\n\033[0m", 38);
	else if (err == 3)
		write (2, "\033[0;31mError: invalid \"second command\"\n\033[0m", 39);
	else if (err == 4)
		write (2, "\033[0;31mUknown error while opening\"outfile\"\n\033[0m",\
		52);
	else if (err == 5)
	{
		write(2, "\033[0;31mError: \"bad arguments\"\n\033[0m", 43);
		write(2, "\033[0;32mUsage: ./pipex infile cmd1 cmd2 outfile\n\033[0m",\
		58);
	}
	else if (err == 6)
		write(2, "\033[0;31mError: \"bad commands\"\n\033[0m", 42);
	else if(err)
		write(2, "\033[0;31mUknown error happend\n\033[0m", 35);
}