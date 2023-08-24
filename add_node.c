/*
 * Author: Deantosh Daiddoh & Lucky Archibong.
 * File: main.c
 */
#include "monty.h"

/**
 *add_stack - Adds the top two elements of the stack.
 *@head: Pointer to the top of the stack.
 *@line_number: Line number in the file.
 *Return - return nothing
 */
void add_stack(stack_t **head, unsigned int line_number)
{

	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int result = (*head)->n + (*head)->next->n;

	pop(head, line_number); /*Remove the top element */
	(*head)->n = result; /*Update the second top element with the result */
}
