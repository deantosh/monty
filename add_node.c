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

	result = *head; /* stores the current head of the list in result */
	new_node = malloc(sizeof(stack_t)); /* allocate memory for a new node */

	if (new_node == NULL) /* checks if memory alloction is successful */
	{ printf("Error\n");
		exit(0); }
	new_node->n = param1; /* Store value passed as an argument in new node */
	new_node->next = result; /* Set new node's 'next' pointer to current head */
	new_node->prev = NULL; /* The new node replaces the head */
	if (result != null)
		result->prev = new_node; /* update 'prev' pointer */
	new_node->next = *head;
	*head = new_node; /* Update the head to point to the new node */
}
