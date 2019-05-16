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
