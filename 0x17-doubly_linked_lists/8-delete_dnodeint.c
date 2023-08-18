#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at
 * a specified index in a doubly linked list.
 * @head: Pointer to the head of the list
 * @index: Index of the node to be deleted
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *a1;
	dlistint_t *a2;
	unsigned int i;

	a1 = *head;

	if (a1 != NULL)
		while (a1->prev != NULL)
			a1 = a1->prev;

	i = 0;

	while (a1 != NULL)
	{
		if (i == index)
		{
			if (i == 0)
			{
				*head = a1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				a2->next = a1->next;

				if (a1->next != NULL)
					a1->next->prev = a2;
			}

			free(a1);
			return (1);
		}
		a2 = a1;
		a1 = a1->next;
		i++;
	}

	return (-1);
}
