#include <stdio.h>
#include <stdlib.h>

/**
 * main - the program to be edited
 * @argc: argument 1
 * @argv: argument 2
 * Return: zero
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);

	exit(EXIT_SUCCESS);
}

