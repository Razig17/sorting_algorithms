#include "sort.h"

/**
 * merge_b - Merges two bitonic sequences
 *
 * @arr: The array to be sorted
 * @low: The starting index of the bitonic sequence
 * @count: The array containing the bitonic sequence
 * @direction: 1 for ascending order, 0 for descending order
 *
 */

void merge_b(int arr[], size_t low, size_t count, int direction)
{
	size_t i;
	size_t k = count / 2;
	int temp;

	if (count > 1)
	{

		for (i = low; i < low + k; i++)
		{
			if ((arr[i] > arr[i + k]) == direction)
			{
				temp = arr[i];
				arr[i] = arr[i + k];
				arr[i + k] = temp;
			}
		}
		merge_b(arr, low, k, direction);
		merge_b(arr, low + k, k, direction);
	}
}
/**
 * bitonic - Sorts a bitonic sequence in both ascending and descending order
 *
 * @arr: The array to be sorted
 * @low: The starting index of the bitonic sequence
 * @count: The length of the bitonic sequence to be sorted
 * @size: Number of elements in the array
 * @direction: 1 for ascending order, 0 for descending order
 *
 */

void bitonic(int arr[], size_t low, size_t count, size_t size, int direction)
{
	size_t k = count / 2;

	if (count <= 1)
		return;

	if (direction == 1)
		printf("Merging [%ld/%ld] (UP):\n", count, size);
	else
		printf("Merging [%ld/%ld] (DOWN):\n", count, size);

	print_array(arr + low, count);

	bitonic(arr, low, k, size, 1);
	bitonic(arr, low + k, k, size, 0);

	merge_b(arr, low, count, direction);
	if (direction)
		printf("Result [%ld/%ld] (UP):\n", count, size);
	else
		printf("Result [%ld/%ld] (DOWN):\n", count, size);
	print_array(arr + low, count);
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 */
void bitonic_sort(int *array, size_t size)
{

	if (array == NULL || size <= 1)
		return;

	bitonic(array, 0, size, size, 1);
}
