#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - excutes the prog.c file
 * @argc: argument 1
 * @argv: argument 2
 * Return: void
 */

int main(int argc, char *argv[])
{
	char *newArgv[] = { NULL, "hey", "there", "welcome", NULL };
	char *newEnvironment[] = { NULL };

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	newArgv[0] = argv[1];

	execve(argv[1], newArgv, newEnvironment);
	perror("execve");
	exit(EXIT_SUCCESS);
}

