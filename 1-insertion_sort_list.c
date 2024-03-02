#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *			in ascending orderusing the Insertion sort algorithm
 *
 * @list: The list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *prev, *curr = NULL;

	if (list  && *list)
		curr = (*list)->next;
	while (curr)
	{
		prev = curr->prev;
		tmp = curr;
		while (prev && tmp->n < prev->n)
		{

			prev->next = tmp->next;
			if (prev->next)
				prev->next->prev = prev;
			tmp->prev = prev->prev;
			if (tmp->prev)
				tmp->prev->next = tmp;
			prev->prev = tmp;
			tmp->next = prev;
			prev = tmp->prev;
			if (tmp->prev == NULL)
				*list = tmp;
			print_list(*list);
			prev = tmp->prev;
		}
		curr = curr->next;
	}
}
