#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints all the arguments
 * @argc: int to be printed
 * @argv: int which will not be used
 * Return: Always 0.
 */

int main(__attribute__((unused))int argc, char **argv)
{
	int idx = 0;

	while (argv[idx])
	{
		printf("argv[%d]: %s\n", idx, argv[idx]);
		idx++;
	}
	return (0);
}

