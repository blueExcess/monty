#ifndef _FLYING_CIRCUS_
#define _FLYING_CIRCUS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
 * struct good_s - opcode and its function
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


/**
 * struct g - global variable structs
 * @head: top of stack
 * @end: bottom of stack
 * @n: value of arg for push
 * @stack_size: number of nodes in current stack
 * @line_num: current line num of file being read
 * @command: current command being executed/processed
 * @line: ?
 * @file: file stream
 *
 * Description: global variables for use in monty
 * interpreter. Some are duplicates, but were added later.
 * Please be careful when modifying functions that
 * remove nodes - need to also modify g.head.
 */
struct g
{
	stack_t *head;
	stack_t *end;
	int n;
	int stack_size;
	int line_num;
	char *command;
	char *line;
	FILE *file;
} g;


/* PROTOTYPES */
/* main.c */
int no_mem_invalid(char *line, int n);
int invalid(int n);

/* helpers.c */
void get_opcode(void);
void free_stack(stack_t *stack);

/* ops1.c */
stack_t *push(stack_t **stack, int n);
int pall(stack_t *stack, unsigned int line_number);
int pint(stack_t *stack, unsigned int line_number);
int pop(stack_t **stack);
int swap(stack_t *stack, unsigned int line_number);

/* ops2.c */
int nop(stack_t *stack, unsigned int line_number);
int _comment(char *str);
int pchar(stack_t *stack, unsigned int line_number);
int pstr(stack_t *stack, unsigned int line_number);

/* rotate.c */
int rotl(stack_t *stack, unsigned int line_number);
int rotr(stack_t *stack, unsigned int line_number);

/* maths.c */
int _add(stack_t *stack, unsigned int line_number);
int _sub(stack_t *stack, unsigned int line_number);
int _mul(stack_t *stack, unsigned int line_number);
int _div(stack_t *stack, unsigned int line_number);
int _mod(stack_t *stack, unsigned int line_number);







#endif /* flying circus */
