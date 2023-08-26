#ifndef MONTY_H
#define MONTY_H

/*include library*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - global variables to store values used during instructions
 *			execution.
 * @head: a pointer to doubly linked list.
 * @stream: a pointer to monty file.
 * @buff: a pointer to buffer containing the read line.
 * @current_line: the current line.
 * @opcode_value: the second parameter on current line.
 *
 * Description: a doubly linked list node structure.
 * for stack, queue, lifo and fifo.
 */
typedef struct globals
{
	stack_t *head;
	FILE *stream;
	char *buff;
	unsigned int current_line;
	char *opcode_value;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*GLOBAL variables*/
extern global_t monty_vars;

/*FUNCTIONS*/

/*file: main.c*/
void init_global_vars(FILE *stream);
FILE *check_usage_file(int argc, char **argv);
void free_monty_vars(void);

/*file: execute_instructions.c*/
void (*select_opcode_func(char *opcode_name))(stack_t **stack, unsigned int line_number);

/*file: stack_functions.c*/
void add_stack(stack_t **head, int param1);
void free_dlistint(stack_t *head);

/*file: instructions_1.c*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);

/*file: instructions_2.c*/
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);

#endif /*MONTY_H*/
