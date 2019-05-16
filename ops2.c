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
 * pchar - print value at top of stack as character
 * @stack: top of stack
 * @line_number: unused
 *
 * Return: 0 on success
 */
int pchar(stack_t *stack, unsigned int line_number)
{
	int a;
	stack_t **stk = &stack;
	(void)line_number;

	if (g.stack_size == 0)
		invalid(9);
	a = pop(stk);
	push(stk, a);
	if (a < 0 || a > 127)
		invalid(10);
	printf("%c\n", a);
	return (0);
}
