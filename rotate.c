/* Holds rotr and rotl functions */
#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: stack to rotate
 * @line_number: line number (unused)
 *
 * Return: 0 on success
 */
int rotl(stack_t *stack, unsigned int line_number)
{
	stack_t *head = stack;
	int temp = 0;

	(void)line_number;

	if (g.stack_size < 2)
		return (0);
	temp = head->n;
	while (head->next != NULL)
	{
		head = head->next;
		head->prev->n = head->n;
	}
	head->n = temp;
	return (0);
}

/**
 * rotr - rotates the stack to the top
 * @stack: stack to rotate
 * @line_number: line number (unused)
 *
 * Return: 0 on success
 */
int rotr(stack_t *stack, unsigned int line_number)
{
	stack_t *head = stack;
	int temp = 0;

	(void)line_number;

	if (g.stack_size < 2)
		return (0);
	while (head->next != NULL)
		head = head->next;
	temp = head->n;
	while (head->prev != NULL)
	{
		head = head->prev;
		head->next->n = head->n;
	}
	head->n = temp;
	return (0);
}
