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
	char *line = NULL, comm[10] = {'\0'};
	ssize_t read = 0;
	size_t bsize = 0, count = 0;
	int value = 0, scanned = 0;
	stack_t *stack;

	if (ac != 2)
		invalid(count, NULL, 3);
	file = fopen(av[1], "r");
	if (!file)
		invalid(count, av[1], 4);
	g.file = file;
	stack = NULL;
	g.head = stack;
	while ((read = getline(&line, &bsize, file)) != -1)
	{
		count++;
		g.line_num = count;
		scanned = sscanf(line, "%s %i", comm, &value);
		g.command = comm;
		g.line = line;
		if (scanned != 2 && strcmp(comm, "push") == 0)
		{
			free_stack(g.head);
			free(line);
			fclose(file);
			invalid(count, line, 2);
		}
		if (strcmp(comm, "push") == 0)
			push(&stack, value);
		else
			get_opcode();
		free(line);
		line = NULL;
	}
	free_stack(g.head);
	free(line);
	fclose(file);
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
		free_stack(g.head);
		free(g.line);
		fclose(g.file);
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
	case 5:
		fprintf(stderr, "L%d: can't pint, stack empty", g.line_num);
		free(g.line);
		fclose(g.file);
		break;
	}
	exit(EXIT_FAILURE);
}
