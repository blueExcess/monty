/* main file for monty interpreter */
#include "monty.h"

/* environment needed? */
int main(int ac, char **av)
{
	FILE *file;
	char *line = NULL, comm[10] = {'\0'}, *push = "push\0";
	ssize_t read = 0;
	size_t bsize = 0, count = 0;
	int value = 0, scanned = 0;


	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &bsize, file)) != -1)
	{
		count++;
		scanned = sscanf(line, "%s %i", comm, &value);
		if (scanned == 1 && strcmp(comm, push) == 0)
			invalid(count, line, 2);
		line = NULL;
		printf("%s %i\n", comm, value);
	}
	return (0);
}


int invalid(int count, char *line, int n)
{
	switch (n)
	{
	case 1:
		fprintf(stderr, "L%d: unknown instruction %s\n", count, line);
		break;
	case 2:
		fprintf(stderr, "L%d: usage: push integer\n", count);
		break;
	}
}
