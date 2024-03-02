#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int tmp, swap = 5;

	while (swap != 0)
	{
		swap = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
	}
}
