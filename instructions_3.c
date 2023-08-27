/*
 * Author: Deantosh Daiddoh & Lucky Archibong
 * File: instructions_3.c
 */

#include "monty.h"

/**
 * _mod - computes the remainder of division between the top element
 *		to the second top element of the stack.
 * @stack: a pointer to the stack.
 * @line_number: the current line of the  opcode being executed.
 *
 * Return: void.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *one = *stack;
	stack_t *two = *stack;
	int num_1, num_2;

	/*if elements are less than two*/
	if (one == NULL || one->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_monty_vars();
		exit(EXIT_FAILURE);
	}

	/*get numbers*/
	num_1 = one->n;
	two = two->next; /*move ptr to next node*/
	num_2 = two->n;

	if (num_1 == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_monty_vars();
		exit(EXIT_FAILURE);
	}

	/*subtrack and assign value back*/
	num_2 %= num_1;
	two->n = num_2;

	/*modify stack*/
	free(one);
	two->prev = NULL;

	/*reset the pos of head*/
	*stack = two;
}
