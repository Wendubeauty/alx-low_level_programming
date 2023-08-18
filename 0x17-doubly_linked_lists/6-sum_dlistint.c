#include "lists.h"

/**
 * sum_dlistint - Computes the sum of all integer values in
 * a doubly linked list.
 * @head: Pointer to the head of the list
 * Return: Sum of all integer values
 */
int sum_dlistint(dlistint_t *head)
{
	int add;

	add = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			add += head->n;
			head = head->next;
		}
	}

	return (add);
}
