#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort Hoare partition algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in array
 *
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array && size > 1)
		hoare_pivot(array, 0, size - 1, size);
}

/**
 * hoare_pivot - Performs the hoare partitioning for QuickSort
 *
 * @arr: The array to be sorted
 * @size: Number of elements in array
 * @low: first element index in the suparray
 * @high: last element index in the suparray
 *
 */
void hoare_pivot(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	size_t i = low - 1;
	size_t j = high + 1;

	if (low >= high || arr == NULL)
		return;
	while (1)
	{
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			break;

		swap_int(&arr[i], &arr[j]);

		print_array(arr, size);
	}
	hoare_pivot(arr, low, i - 1, size);
	hoare_pivot(arr, i, high, size);
}

/**
 * swap_int - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
