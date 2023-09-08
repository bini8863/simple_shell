#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints $ and when value is inputed it writes it in a new line.
 * @argc: argument 1
 * @argv: argument 2
 * Return: 0
 */

int main(__attribute__((unused))int argc, __attribute__((unused)) char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");

	nread = getline(&line, &len, stdin);
	printf("%s", line);
	printf("Number of characters: %ld\n", nread);

	free(line);
	exit(EXIT_SUCCESS);
}


