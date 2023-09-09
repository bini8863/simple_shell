#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main: waits for the program to excute
 * @argc: argument 1
 * @argv: argument 2
 * Return: zero
 */

int main(int argc, char *argv[])
{
	pid_t child_pid;
	pid_t my_wait;
	int wstatus;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		printf("child pid is %ld", (long) getpid());
		if (argc == 1)
		{
			pause();
		}
		_exit(atoi(argv[1]));
	}
	else
	{
		do {
			my_wait = waitpid(child_pid, &wstatus, WCONTINUED | WUNTRACED);

			if (my_wait == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
			if (WIFEXITED(wstatus))
			{
				printf("terminated normally, status is %d\n", WEXITSTATUS(wstatus));
			}
			else if (WIFSIGNALED(wstatus))
			{
				printf("terminated with a signal %d\n", WTERMSIG(wstatus));
			}
			else if (WIFSTOPPED(wstatus))
			{
				printf("stopped by dilivering of signal %d\n", WSTOPSIG(wstatus));
			}
			else if (WIFCONTINUED(wstatus))
			{
				printf("resumed \n");
			}
		}
			while (!WIFEXITED(wstatus) && (!WIFSIGNALED(wstatus)));
		exit(EXIT_SUCCESS);
	}
}

