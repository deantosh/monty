/*
 * Author: Deantosh Daiddoh & Lucky Archibong
 * File: instructions_2.c
 */

#include "monty.h"

/**
 * _add - adds the two top elements of the stack, removes the first
 *		element and save result on the second element.
 * @stack: a pointer to the stack.
 * @line_number: the current line of opcode in monty file.
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *one = *stack;
	stack_t *two = *stack;

	if (one->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		free_monty_vars();
		exit(EXIT_FAILURE);
	}

	/*move ptr to second node*/
	two = two->next;

	/*add two values*/
	two->n += one->n;

	/*free the first node*/
	free(one);

	/*set node*/
	two->prev = NULL;
	*stack = two;
}
