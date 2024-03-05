#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in array
 *
 */

void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size <= 1)
		return;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;
	split(array, tmp, 0, size);

	free(tmp);
}

/**
 * split - Splits the array into right and left halves
 *	   until there is only one element
 * @array: The array to be sorted
 * @copy: A copy array that will store the result
 * @first: The index of the first elemnt
 * @last: The index of the last elemnt
 */
void split(int *array, int *copy, size_t first, size_t last)
{
	size_t mid;

	if (last - first <= 1)
		return;

	mid = (first + last) / 2;
	split(array, copy, first, mid);
	split(array, copy, mid, last);

	printf("Merging...\n[left]: ");
	print_array((array + first), mid - first);
	printf("[right]: ");
	print_array((array + mid), last - mid);

	merge(array, copy, first, mid, last);
	copy_arr(array + first, copy + first, last - first);
	printf("[Done]: ");
	print_array(array + first, last - first);
}

/**
 * merge - Merges two sorted halves
 * @array: The array to be sorted
 * @copy: A copy array that will store the result
 * @first: The index of the first elemnt
 * @mid: The middle index
 * @last: The index of the last elemnt
 */

void merge(int *array, int *copy, size_t first, size_t mid, size_t last)
{
	size_t i = first, j = mid, k;

	for (k = first; k < last; k++)
	{
		if (i < mid && (j >= last || array[i] <= array[j]))
		{
			copy[k] = array[i];
			i++;
		}
		else
		{
			copy[k] = array[j];
			j++;
		}
	}
}

/**
 * copy_arr - Copies an array from a source array to a destination array
 * @dest: The destination array
 * @src: The source array
 * @size: The number of elements to be copied
 */
void copy_arr(int *dest, int *src, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		dest[i] = src[i];
}
