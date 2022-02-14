#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int	main(void)
{
	printf("%s %d\n", "current process ID", getpid());
	printf("%s %d\n", "parent of current process ID:", getppid());

    return (0);
}