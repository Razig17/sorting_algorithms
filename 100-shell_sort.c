#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i;
	int swap = 1, tmp;

	if (array == NULL || size <= 1)
		return;
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		swap = 1;
		while (swap == 1)
		{
			swap = 0;

			for (i = 0; i + gap < size; i++)
			{
				if (array[i] > array[i + gap])
				{
					tmp = array[i];
					array[i] = array[i + gap];
					array[i + gap] = tmp;
					swap = 1;
				}
			}
		}
		gap /= 3;
		print_array(array, size);
	}
}
