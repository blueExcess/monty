#include <stdio.h>
#include "monty.h"
/* functions for various opcodes including push */

/**
 * push - add node to top of stack
 * @stack: position of stack
 * @n: value to push to stack
 *
 * Return: idk yet.
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
	return (new);
}

/**
 * pall - Print values on the stack, starting from the top
 * @stack: pointer to the stack
 *
 * Return: the number of nodes
 */
size_t pall(const stack_t *stack)
{
	size_t ele;

	if (stack == NULL)
		return (0);
	for (ele = 0; stack != NULL; ele++)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
	return (ele);
}
