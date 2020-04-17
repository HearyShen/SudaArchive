#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
pid_t pid;

	/* fork a child process */
	pid = fork();

	if(pid < 0)
	{
		fprintf(stderr, "fork failed!\n");
		exit(-1);
	}
	else if(pid == 0) /* child process */
	{
		execlp("./helloworld","helloworld",NULL);
	}
	else	/* parent process */
	{
	/* parent will wait for the child to completed */
		wait(NULL);
		printf("Child Completed!\n");
		exit(0);
	}
}
