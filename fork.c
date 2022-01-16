#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	
	if(pid<0)
	{
		printf(stderr, "Fork failed.\n");
		return 1;
	}
	else if (pd == 0)
		execlp("/bin/ls", "ls", NULL);
	else
	{
		wait(NULL);
		printf("Child Complete\n");
	}

