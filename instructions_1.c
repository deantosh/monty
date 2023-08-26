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

	/*check if val is digit and positive*/
	for (i = 0; monty_vars.opcode_value[i] != '\0'; i++)
	{
		val = isdigit(monty_vars.opcode_value[i]);
		if (val == 0 && monty_vars.opcode_value[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push this integer\n", line_number);
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
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_monty_vars();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}

/**
 * _pop - removes the element at the top of the stack.
 * @stack: a pointer to the stack.
 * @line_number: the current line of opcode in monty file.
 *
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	stack_t *tmp;

	current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_monty_vars();
		exit(EXIT_FAILURE);
	}
	if (current->next)
	{
		/*remove element from stack*/
		tmp = current;
		current = current->next;
		free(tmp);
		current->prev = NULL;
	}
	else
	{
		free(current);
		current = NULL;
	}

	/*reset head*/
	*stack = current;
}

/**
 * _swap - swaps the two top elements of the stack.
 * @stack: a pointer to the stack.
 * @line_number: the current line of opcode in monty file.
 *
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *one = *stack;
	stack_t *two = *stack;
	stack_t *three = *stack;

	if (one == NULL || one->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_monty_vars();
		exit(EXIT_FAILURE);
	}

	/*move ptr to swap*/
	two = two->next;
	three = three->next->next;

	if (one->next->next == NULL)/*if two elements in list*/
	{
		one->prev = two;
		one->next = NULL;
		two->prev = NULL;
		two->next = one;
	}
	else
	{
		/*swap the nodes if more than two*/
		two->prev = NULL;
		one->prev = two;
		two->next = one;
		one->next = three;
		three->prev = one;
	}

	/*move head*/
	*stack = two;
}
