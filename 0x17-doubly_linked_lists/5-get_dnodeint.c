#include "lists.h"

/**
 * get_dnodeint_at_index - Retrieves a node at
 * a specified index in a doubly linked list.
 * @head: Pointer to the head of the list
 * @index: Index of the desired node
 * Return: Address of the node at the specified index,
 * or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int len;
	dlistint_t *p;

	len = 0;
	if (head == NULL)
	return (NULL);

	p = head;
	while (p)
	{
	if (index == len)
	return (p);
	len++;
	p = p->next;
	}
	return (NULL);
}
