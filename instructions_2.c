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

	if (one == NULL || one->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
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

/**
 * _nop - does not do anything.
 * @stack: a pointer to the stack.
 * @line_number: the current line of opcode in monty file.
 *
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - subtracts the top element of the stack to the second top
 *		element of the stack.
 * @stack: a pointer to the stack.
 * @line_number: the current line of the  opcode being executed.
 *
 * Return: void.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *one = *stack;
	stack_t *two = *stack;
	int num_1, num_2;

	/*if elements are less than two*/
	if (one == NULL || one->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_monty_vars();
		exit(EXIT_FAILURE);
	}

	/*get numbers*/
	num_1 = one->n;
	two = two->next; /*move ptr to next node*/
	num_2 = two->n;

	/*subtrack and assign value back*/
	num_2 -= num_1;
	two->n = num_2;

	/*modify stack*/
	free(one);
	two->prev = NULL;

	/*reset the pos of head*/
	*stack = two;
}

/**
 * _div - divides the top element of the stack to the second top
 *		element of the stack.
 * @stack: a pointer to the stack.
 * @line_number: the current line of the  opcode being executed.
 *
 * Return: void.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *one = *stack;
	stack_t *two = *stack;
	int num_1, num_2;

	/*if elements are less than two*/
	if (one == NULL || one->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_monty_vars();
		exit(EXIT_FAILURE);
	}

	/*get numbers*/
	num_1 = one->n;
	if (num_1 == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_monty_vars();
		exit(EXIT_FAILURE);
	}
	two = two->next; /*move ptr to next node*/
	num_2 = two->n;

	/*subtrack and assign value back*/
	num_2 /= num_1;
	two->n = num_2;

	/*modify stack*/
	free(one);
	two->prev = NULL;

	/*reset the pos of head*/
	*stack = two;
}

/**
 * _mul - multiply the top element of the stack to the second top
 *		element of the stack.
 * @stack: a pointer to the stack.
 * @line_number: the current line of the  opcode being executed.
 *
 * Return: void.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *one = *stack;
	stack_t *two = *stack;
	int num_1, num_2;

	/*if elements are less than two*/
	if (one == NULL || one->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_monty_vars();
		exit(EXIT_FAILURE);
	}

	/*get numbers*/
	num_1 = one->n;
	two = two->next; /*move ptr to next node*/
	num_2 = two->n;

	/*subtrack and assign value back*/
	num_2 *= num_1;
	two->n = num_2;

	/*modify stack*/
	free(one);
	two->prev = NULL;

	/*reset the pos of head*/
	*stack = two;
}
