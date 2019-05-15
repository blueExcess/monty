#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * get_opcode - function to get the correct function
 * @str: string with the correct function name
 *
 * Return: not sure yet
 */
void get_opcode(void)
{
	good_t commands[] = {
		{"pall", pall}, {"pint", pint}/*, {"swap", swap},
		{"add", add}, {"nop", nop}, {"sub", sub},
		{"div", div}, {"mul", mul}, {"mod", mod},
		{"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}*/
	};
	if (strcmp(g.command, commands[1].opcode) == 0)
	{
		commands[1].f(g.head, g.line_num);
	}
}

/**
 * free_stack - free memory from a stack
 * @stack: stack to free
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	current = stack;
	while (current != NULL)
	{
		current = current->next;
		free(stack);
		stack = current;
	}
}
