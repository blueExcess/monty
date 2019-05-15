/* functions for various opcodes including push */

/**
 * push - add node to top of stack
 * @stack: position of stack
 * @n: value to push to stack
 *
 * Return: idk yet.
 */
stack_t *push(dlistint_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
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
