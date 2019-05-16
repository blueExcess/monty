/* core functions for monty interpreter */
#include "monty.h"

/**
 * get_opcode - function to get the correct function
 *
 * Return: not sure yet
 */
void get_opcode(void)
{
	int i = 0;

	good_t commands[] = {
		{"pall", pall}, {"pint", pint}, {"swap", swap},
		{"add", _add}, {"nop", nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul}, {"mod", _mod},
		{"pchar", pchar},
    /**
    *{"pstr", pstr}, {"rotl", rotl},
		*{"rotr", rotr},
    */
		{NULL, NULL}
	};
	while (commands[i].f != NULL)
	{
		if (strcmp(g.command, commands[i].opcode) == 0)
		{
			commands[i].f(g.head, g.line_num);
			return;
		}
		i++;
	}
	invalid(1);
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
