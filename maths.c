/* new functions to be merged into opstuff files for fun and profit */

/**
 * add - add top two of stack together and return result
 * @stack: top of stack
 * @line_number: wish this was a shorter var name
 *
 * Return: prints result - 0 on success, 1 on fail
 */
int add(stack_t *stack, unsigned int line_number)
{
	int a = 0, b = 0;
	unsigned int ln = line_number;

	if (g.stack_size > 2)
	{
		a = pop(stack, line_number);
		b = pop(stack, line_number);
		push(stack, a + b);
		printf("%d\n", a + b); /* maybe print from stack directly? */
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		/* free all stuff or call error handling func? */
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * sub - subtract top two of stack together and return result
 * @stack: top of stack
 * @line_number: wish this was a shorter var name
 *
 * Return: prints result - 0 on success, 1 on fail
 */
int sub(stack_t *stack, unsigned int line_number)
{
	int a = 0, b = 0;
	unsigned int ln = line_number;

	if (g.stack_size > 2)
	{
		a = pop(stack, line_number);
		b = pop(stack, line_number);
		push(stack, a - b);
		printf("%d\n", a - b); /* maybe print from stack directly? */
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		/* free all stuff or call error handling func? */
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * mul - multiply top two of stack together and return result
 * @stack: top of stack
 * @line_number: wish this was a shorter var name
 *
 * Return: prints result - 0 on success, 1 on fail
 */
int mul(stack_t *stack, unsigned int line_number)
{
	int a = 0, b = 0;
	unsigned int ln = line_number;

	if (g.stack_size > 2)
	{
		a = pop(stack, line_number);
		b = pop(stack, line_number);
		push(stack, a * b);
		printf("%d\n", a * b); /* maybe print from stack directly? */
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		/* free all stuff or call error handling func? */
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * div - divide top two of stack together and return result
 * @stack: top of stack
 * @line_number: wish this was a shorter var name
 *
 * Return: prints result - 0 on success, 1 on fail
 */
int div(stack_t *stack, unsigned int line_number)
{
	int a = 0, b = 0;
	unsigned int ln = line_number;

	if (g.stack_size > 2)
	{
		a = pop(stack, line_number);
		if (a == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", ln);
			/* free stuff */
			exit(EXIT_FAILURE);
		}
		b = pop(stack, line_number);
		push(stack, a / b);
		printf("%d\n", a / b); /* maybe print from stack directly? */
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		/* free all stuff or call error handling func? */
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * mod - modulo top two of stack together and return result
 * @stack: top of stack
 * @line_number: wish this was a shorter var name
 *
 * Return: prints result - 0 on success, 1 on fail
 */
int mod(stack_t *stack, unsigned int line_number)
{
	int a = 0, b = 0;
	unsigned int ln = line_number;

	if (g.stack_size > 2)
	{
		a = pop(stack, line_number);
		if (a == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", ln);
			/* free stuff */
			exit(EXIT_FAILURE);
		}
		b = pop(stack, line_number);
		push(stack, a % b);
		printf("%d\n", a % b); /* maybe print from stack directly? */
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		/* free all stuff or call error handling func? */
		exit(EXIT_FAILURE);
	}
	return (0);
}
