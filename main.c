/* main file for monty interpreter */
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * main - take input from files and parse then call opcodes
 * @ac: number of arguments
 * @av: list of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int ac, char **av)
{
	FILE *file;
	char *line = NULL, comm[10] = {'\0'}, *push = "push\0";
	ssize_t read = 0;
	size_t bsize = 0, count = 0;
	int value = 0, scanned = 0;


	if (ac != 2)
		invalid(count, NULL, 3);
	file = fopen(av[1], "r");
	if (!file)
		invalid(count, av[1], 4);
	while ((read = getline(&line, &bsize, file)) != -1)
	{
		count++;
		scanned = sscanf(line, "%s %i", comm, &value);
		if (scanned == 1 && strcmp(comm, push) == 0)
		{
			fclose(file);
			/* Maybe free here instead of in function, not sure */
			invalid(count, line, 2);
		}
			line = NULL;
                /* debug */
		printf("%s %i\n", comm, value);
	}
	fclose(file);
	free(line);
	return (0);
}

/**
 * invalid - error handling function
 * @count: line count
 * @line: current instruction (not parsed)
 * @n: error code to run
 *
 * Return: 0 on success, 1 on failure
 */
int invalid(int count, char *line, int n)
{
	switch (n)
	{
	case 1:
		fprintf(stderr, "L%d: unknown instruction %s\n", count, line);
		break;
	case 2:
		fprintf(stderr, "L%d: usage: push integer\n", count);
		break;
	case 3:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 4:
		fprintf(stderr, "Error: Can't open file %s\n", line);
		break;
	}
	free(line);
	exit(EXIT_FAILURE);
}
