#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - forks something
 * Return: 0
 */

int main(void)
{
	pid_t my_pid;
	pid_t pid;

	printf("Before calling fork\n");
	pid = fork();

	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}

	printf("After calling fork\n");
	my_pid = getpid();
	printf("After calling fork, pid is %u\n", pid);
	printf("My pid is %u\n", my_pid);
	return (0);
}

