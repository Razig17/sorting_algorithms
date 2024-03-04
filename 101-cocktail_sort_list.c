#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *		in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: The list to be sorted
 *
 */

void cocktail_sort_list(listint_t **list)
{
	int swaping = 1;
	listint_t *tmp;

	if (list == NULL || *list == NULL)
		return;

	tmp = *list;

	while (swaping == 1)
	{
		swaping = 0;
		while (tmp->next && tmp)
		{

			if (tmp->n > tmp->next->n)

				swaping = swap(tmp, tmp->next, list);
			else
				tmp = tmp->next;
		}

		while (tmp->prev && tmp)
		{
			if (tmp->n < tmp->prev->n)

				swaping = swap(tmp->prev, tmp, list);
			else
				tmp = tmp->prev;
		}
	}
}

/**
 * swap - swaps two listint lists
 *
 * @prev: The first list
 * @tmp: The second list
 *
 * Return: Returnes 1 or 0 if it fails
 *
 */

int swap(listint_t *prev, listint_t *tmp, listint_t **list)
{
	if (prev == NULL || tmp == NULL || list == NULL)
		return (0);

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
	return (1);
}