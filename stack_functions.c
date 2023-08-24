#include "monty.h"
/**
 * add_stack - add node to the head stack
 * @head: Where the stack begins
 * @param1 : the new value to adding
 * Return: no return
*/
void add_stack(stack_t **head, int param1)
{

	stack_t *new_node, *result;

	result = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	new_node->n = param1;
	new_node->next = result;
	new_node->prev = NULL;

	if (result != NULL)
		result->prev = new_node;

	new_node->next = *head;
	*head = new_node;
}

/**
 * free_dlistint - frees the doubly linked list.
 * @head: a pointer to the doubly linked list.
 *
 * Return: void.
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
