#ifndef _FLYING_CIRCUS_
#define _FLYING_CIRCUS_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* STRUCTS */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        int (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct good_s
{
        char *opcode;
        int (*f)(stack_t *stack, unsigned int line_number);
} good_t;

struct g
{
	stack_t *head;
	stack_t *end;
	int n;
	int stack_size;
	int line_num;
	char *command;
} g;

/* PROTOTYPES */
int invalid(int count, char *line, int n);
void get_opcode(void);
stack_t *push(stack_t **stack, int n);
int pall(stack_t *stack, unsigned int line_number);
void free_stack(stack_t *stack);
int pint(stack_t *stack, unsigned int line_number);




#endif /* flying circus */
