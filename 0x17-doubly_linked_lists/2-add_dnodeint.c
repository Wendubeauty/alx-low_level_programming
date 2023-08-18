#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of
 * a doubly linked list.
 * @head: Pointer to the head of the list
 * @n: Integer value to store in the new node
 * Return: Address of the new node, or NULL on failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *a;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	a = *head;

	if (a != NULL)
	{
		while (a->prev != NULL)
			a = a->prev;
	}

	new_node->next = a;

	if (a != NULL)
		a->prev = new_node;

	*head = new_node;

	return (new_node);
}
