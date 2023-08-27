/*
 * Author: Deantosh M Daiddoh & Lucky Archibong
 * File: queue_functions.c
 */

#include "monty.h"

/**
 * add_queue - adds value at the end of the doubly linked list
 *		creating a queue.
 * @head: a pointer to the linked list.
 * @value: the integer to add to the queue.
 *
 * Return: a pointer to the queue.
 */
void add_queue(stack_t **head, int value)
{
	stack_t *current, *new;

	/*allocate mem for the new node*/
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_monty_vars();
		exit(EXIT_FAILURE);
	}

	/*add element*/
	new->n = value;
	new->next = NULL;

	current = *head;

	if (current == NULL)
	{
		new->prev = current;
		*head = new;
	}
	else
	{
		/*move ptr to end of list*/
		while (current->next)
			current = current->next;

		/*add node at end of list*/
		current->next = new;
		new->prev = current;
	}
}
