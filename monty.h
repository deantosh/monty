#ifndef MONTY_H
#define MONTY_H

/*include library*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>

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

/*FUNCTIONS*/

/*file: main.c*/
void init_global_vars();
FILE *check_usage_file(int argc, char **argv);

/*file: execute_instructions*/
void (*select_opcode_func(char *opcode_name))(stack_t **stack, unsigned int line_number);

#endif /*MONTY_H*/
