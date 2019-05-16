#include <stdio.h>
#include "monty.h"
/* functions for various opcodes including push */

/**
 * push - add node to top of stack
 * @stack: position of stack
 * @n: value to push to stack
 *
 * Return: pointer to a new stack.
 */
stack_t *push(stack_t **stack, int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	else
		new->next = NULL;
	*stack = new;
	g.stack_size++;
	g.head = new;
	return (new);
}

/**
 * pall - Print values on the stack, starting from the top
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: -1 for error, 0 for success
 */
int pall(stack_t *stack, unsigned int line_number)
{
	size_t ele;

	(void)line_number;
	if (stack == NULL)
		return (-1);
	for (ele = 0; stack != NULL; ele++)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
	return (0);
}

/**
 * pint - prints top of stack
 * @stack: stack to print from
 * @line_number: line number
 *
 * Return: 0 on success, -1 on error
 */
int pint(stack_t *stack, unsigned int line_number)
{
	(void)line_number;
	if (stack == NULL || g.stack_size == 0)
	{
		invalid(5);
		return (-1);
	}
	printf("%i\n", stack->n);
	return (0);
}
