#include "sort.h"


/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array  && size > 1)
		quick_sort_recursion(array, 0, size - 1, size);
}

/**
 * quick_sort_recursion - Sorts an array of integers in ascending order
 * using the Quick sort algorithm recursively
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @lo: first element index in the sup array
 * @hi: last element index in the sup array
 *
 */
void quick_sort_recursion(int array[], size_t lo, size_t hi, size_t size)
{
	size_t pivot;

	if (lo < hi)
	{
		if (lo < size && hi < size)
		{
			pivot = lomuto_pivot(array, lo, hi, size);

			quick_sort_recursion(array, lo, pivot - 1, size);
			quick_sort_recursion(array, pivot + 1, hi, size);
		}
	}
}

/**
 * lomuto_pivot - Performs the Lomuto partitioning for QuickSort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @lo: first element index in the suparray
 * @hi: last element index in the suparray
 *
 * Return: The index of the pivot after partitioning.
 */
size_t lomuto_pivot(int array[], size_t lo, size_t hi, size_t size)
{
	size_t i = lo - 1, j;
	int tmp;
	int high = array[hi];

	for (j = lo; j <= hi; j++)
	{
		if (array[j] < high)
		{
			i++;
			if (i == j)
				continue;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;

			print_array(array, size);
		}
	}
	if (hi == i + 1)
		return (i + 1);
	tmp = array[i + 1];
	array[i + 1] = array[hi];
	array[hi] = tmp;
	print_array(array, size);
	return (i + 1);
}
