/* new functions to be merged into opstuff files for fun and profit */
#include "monty.h"

/**
 * _add - add top two of stack together and return result
 * @stack: top of stack
 * @line_number: wish this was a shorter var name
 *
 * Return: prints result - 0 on success, 1 on fail
 */
int _add(stack_t *stack, unsigned int line_number)
{
	int a = 0, b = 0;
	stack_t **stk = &stack;
	(void)line_number;

	if (g.stack_size >= 2)
	{
		a = pop(stk);
		b = pop(stk);
		push(stk, b + a);
	}
	else
		invalid(6);
	return (0);
}

/**
 * _sub - subtract top two of stack together and return result
 * @stack: top of stack
 * @line_number: wish this was a shorter var name
 *
 * Return: prints result - 0 on success, 1 on fail
 */
int _sub(stack_t *stack, unsigned int line_number)
{
	int a = 0, b = 0;
	stack_t **stk = &stack;
	(void)line_number;

	if (g.stack_size >= 2)
	{
		a = pop(stk);
		b = pop(stk);
		push(stk, b - a);
	}
	else
		invalid(6);
	return (0);
}

/**
 * _mul - multiply top two of stack together and return result
 * @stack: top of stack
 * @line_number: wish this was a shorter var name
 *
 * Return: prints result - 0 on success, 1 on fail
 */
int _mul(stack_t *stack, unsigned int line_number)
{
	int a = 0, b = 0;
	stack_t **stk = &stack;
	(void)line_number;

	if (g.stack_size >= 2)
	{
		a = pop(stk);
		b = pop(stk);
		push(stk, b * a);
	}
	else
		invalid(6);
	return (0);
}

/**
 * _div - divide top two of stack together and return result
 * @stack: top of stack
 * @line_number: wish this was a shorter var name
 *
 * Return: prints result - 0 on success, 1 on fail
 */
int _div(stack_t *stack, unsigned int line_number)
{
	int a = 0, b = 0;
	stack_t **stk = &stack;
	(void)line_number;

	if (g.stack_size >= 2)
	{
		a = pop(stk);
		if (a == 0)
			invalid(7);
		b = pop(stk);
		push(stk, b / a);
	}
	else
		invalid(6);
	return (0);
}

/**
 * _mod - modulo top two of stack together and return result
 * @stack: top of stack
 * @line_number: wish this was a shorter var name
 *
 * Return: prints result - 0 on success, 1 on fail
 */
int _mod(stack_t *stack, unsigned int line_number)
{
	int a = 0, b = 0;
	stack_t **stk = &stack;
	(void)line_number;

	if (g.stack_size >= 2)
	{
		a = pop(stk);
		if (a == 0)
			invalid(7);
		b = pop(stk);
		push(stk, b % a);
	}
	else
		invalid(6);
	return (0);
}
