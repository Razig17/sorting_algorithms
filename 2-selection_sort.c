#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, swap;

	for (i = 0; i < size; i++)
	{
		swap = 1;
		tmp = i;
		for (j = i; j < size; j++)
		{

			if (array[j] < array[tmp])
			{
				tmp = j;
				swap = 0;
			}
		}

		if (swap == 0)
		{
			j = array[i];
			array[i] = array[tmp];
			array[tmp] = j;
			print_array(array, size);
		}
	}
}
