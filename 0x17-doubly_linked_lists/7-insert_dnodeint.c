#include "lists.h"
/**
 * insert_dnodeint_at_index - Inserts a new node at a
 * specified index in a doubly linked list.
 * @h: Pointer to the head of the list
 * @idx: Index at which the new node should be inserted
 * @n: Integer value to store in the new node
 * Return: Address of the new node, or NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *_head;
	unsigned int i;

	new_node = NULL;
	if (idx == 0)
		new_node = add_dnodeint(h, n);
	else
	{
		_head = *h;
		i = 1;
		if (_head != NULL)
			while (_head->prev != NULL)
				_head = _head->prev;
		while (_head != NULL)
		{
			if (i == idx)
			{
				if (_head->next == NULL)
					new_node = add_dnodeint_end(h, n);
				else
				{
					new_node = malloc(sizeof(dlistint_t));
					if (new_node != NULL)
					{
						new_node->n = n;
						new_node->next = _head->next;
						new_node->prev = _head;
						_head->next->prev = new_node;
						_head->next = new_node;
					}
				}
				break;
			}
			_head = _head->next;
			i++;
		}
	}

	return (new_node);
}
