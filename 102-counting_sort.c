#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 */

void counting_sort(int *array, size_t size)
{
	int j, max, *count, *sorted;
	size_t i;

	if (array == NULL || size <= 1)
		return;
	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * max + 1);
	if (count == NULL)
		return;
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	for (j = 0; j <= max; j++)
		count[0] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];
	print_array(count, max + 1);
	for (j = size - 1; j >= 0; j--)
	{
		sorted[--count[array[j]]] = array[j];
	}

	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	free(sorted);
	free(count);
}
