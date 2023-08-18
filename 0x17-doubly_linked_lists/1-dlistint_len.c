#include "lists.h"

/**
 * dlistint_len - Counts the number of nodes in
 * a doubly linked list.
 * @h: Pointer to the head of the list
 * Return: Number of nodes in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int all;

	all = 0;

	if (h == NULL)
		return (all);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		all++;
		h = h->next;
	}

	return (all);
}
