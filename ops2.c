/* second page of opcodes (not really opcodes) */
#include "monty.h"

/**
 * nop - a function that does nothing
 * @stack: top of stack
 * @line_number: unused
 *
 * Return: 0 on success
 */
int nop(stack_t *stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;


	return (0);
}
/**
 * _comment - checks for # symbol in opcode
 * @str: string to check for a #
 *
 * Return: 1 if # found, -1 if not found
 */
int _comment(char *str)
{
	int i;

	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\v')
		{
			i++;
			continue;
		}
		else if (str[i] == '#')
			return (1);
		else
			return (-1);
	}
	return (-1);
}
