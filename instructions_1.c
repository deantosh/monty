/*
 * Author: Deantosh Daiddoh & Luck Archibong.
 * File: instruction_1.c
 */

#include "monty.h"

/**
 * _push - push a new element to the stack.
 * @stack: a pointer to the stack.
 * @line_number: the current line of opcode in monty file.
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int stack_value, val, i;

	/*check if the opcode value is provided*/
	if (monty_vars.opcode_value ==  NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_monty_vars(); /*free mem*/
		exit(EXIT_FAILURE);
	}

	/*check if val is digit and not a negative number*/
	for (i = 0; monty_vars.opcode_value[i] != '\0'; i++)
	{
		val = isdigit(monty_vars.opcode_value[i]);
		if (val == 0 && monty_vars.opcode_value[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_monty_vars(); /*free mem*/
			exit(EXIT_FAILURE);
		}
	}

	stack_value = atoi(monty_vars.opcode_value);

	/*add element to stack*/
	add_stack(stack, stack_value);
}

/**
 * _pall - prints all the elements in the stack.
 * @stack: a pointer to the stack.
 * @line_number: the current line of opcode in monty file.
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - prints the element at the top of the stack.
 * @stack: a pointer to the stack.
 * @line_number: the current line of opcode in monty file.
 *
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		free_monty_vars();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
