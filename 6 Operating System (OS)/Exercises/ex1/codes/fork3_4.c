#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int value = 5;

int main()
{
pid_t pid;

	/* fork a child process */
	pid = fork();

	if(pid == 0) /* child process */
	{
		value += 15;
	}
	else if(pid > 0) /* parent process */
	{
	/* parent will wait for the child to completed */
		wait(NULL);
		printf("PARENT: value = %d\n", value);
		exit(0);
	}
}
