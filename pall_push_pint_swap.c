/*
 *Author: Deantosh Daiddoh &Lucky Archibong.
 *File: pall_push_pint_swap.c
 */
#include "monty.h"

/**
 *_push - Pushes an integer onto the stack.
 *@head: Pointer to the top of the stack.
 *@line_number: Line number in file.
 *@argument: The argument to push onto the stack.
 *Return - return nothing
 */
void _push(stack_t **head, unsigned int line_number, const char *argument)
{
	int n, i = 0, flag = 0;

	if (!argument)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*statement to check if argument is a negative val */
	if (argument[0] == '-')
		i++;

	while (argument[i] != '\0')
	{
		if (argument[i] < '0' || argument[i] > '9')
		{
			flag = 1;
			break;
		}

		i++;
	}

	if (flag == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(argument);
	add_stack(head, n);
}

/**
 *_pall - prints the value at top of stack
 *@head: top of stack
 *@line_number: not used in this function
 *Return: return nothing
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void) line_number;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 *_pop - removes the top element of the stack
 *@head: top of the stack
 *@line_number: gets the line number
 *Return: return nothing
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	h = *head;
	*head = h->next;
	free(h);
}

/**
 *_swap - adds the top two elements of the stack.
 *@head: top of the stack
 *@line_number: line number of the file
 *Return: return nothing
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, result;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	h = *head;
	result = h->n;
	h->n = h->next->n;
	h->next->n = result;
}
