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
	char *line = NULL, comm[64] = {'\0'};
	ssize_t read = 0;
	size_t bsize = 0, count = 0;
	int value = 0, scanned = 0;
	stack_t *stack;

	if (ac != 2)
		no_mem_invalid(NULL, 1);
	file = fopen(av[1], "r");
	if (!file)
		no_mem_invalid(av[1], 2);
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
			invalid(2);
		}
		if (strcmp(comm, "push") == 0)
			push(&stack, value);
		else if (strcmp(comm, "pop") == 0)
			pop(&stack);
		else
			get_opcode();
		stack = g.head;
		free(line);
		line = NULL;
	}
	free_stack(g.head);
	free(line);
	fclose(file);
	return (0);
}
/**
 * no_mem_invalid - error handling function before memory is allocated
 * @line: current instruction (not parsed)
 * @n: error code to run
 *
 * Return: 0 on success, 1 on failure
 */
int no_mem_invalid(char *line, int n)
{
	switch (n)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n", line);
		break;
	}
	exit(EXIT_FAILURE);
}



/**
 * invalid - error handling function
 * @n: error code to run
 *
 * Return: 0 on success, 1 on failure
 */
int invalid(int n)
{
	switch (n)
	{
	case 1:
		/* No newline because g.line already includes one...?*/
		fprintf(stderr, "L%d: unknown instruction %s\n", g.line_num, g.command);
		break;
	case 2:
		fprintf(stderr, "L%d: usage: push integer\n", g.line_num);
		break;
	case 5:
		fprintf(stderr, "L%d: can't pint, stack empty\n", g.line_num);
		break;
	case 6:
		fprintf(stderr, "L%d: can't %s, stack too short\n", g.line_num, g.command);
		break;
	case 7:
		fprintf(stderr, "L%d: division by zero\n", g.line_num);
		break;
	case 8:
		fprintf(stderr, "L%d: can't pop an empty stack\n", g.line_num);
		break;

	}
	free_stack(g.head);
	free(g.line);
	fclose(g.file);
	exit(EXIT_FAILURE);
}
