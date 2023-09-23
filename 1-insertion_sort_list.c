#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion Sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{

	listint_t *curr, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr = (*list)->next;

	while (curr != NULL)
	{
		temp = curr->next;
		prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			prev->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = prev;

			curr->prev = prev->prev;
			curr->next = prev;
			prev->prev = curr;

			if (curr->prev == NULL)
				*list = curr;
			else
				curr->prev->next = curr;

			print_list(*list);

			prev = curr->prev;
		}

		curr = temp;
	}
}
