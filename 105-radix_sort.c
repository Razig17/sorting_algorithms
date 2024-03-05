#include "sort.h"

/**
 * bubble - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: The current digit position (exponent)
 *
 */

void bubble(int *array, size_t size, size_t exp)
{
	size_t i, j;
	int tmp, swap = 5;

	for (j = 0; j < size; j++)
	{
		swap = 0;
		for (i = 0; i < size - 1; i++)
		{
			if ((array[i] / exp) % 10 > (array[i + 1] / exp) % 10)
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swap = 1;
			}
		}
		if (swap == 0)
			break;
	}
}
/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 */
void radix_sort(int *array, size_t size)
{
	int max = array[0];
	size_t i, exp;

	if (array == NULL || size <= 1)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (exp = 1; max / exp > 0; exp *= 10)
	{

		bubble(array, size, exp);
		print_array(array, size);
	}
}
