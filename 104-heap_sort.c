#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size <= 1)
		return;

	heapify(array, size);
	for (i = size - 1; i > 0; i--)
	{
		swap_int(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}

/**
 * heapify - Builds a max-heap from an unsorted array using sift-down.
 * @array: The input array.
 * @size: The size of the array.
 */

void heapify(int *array, size_t size)
{
	long int i;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, i, size - 1, size);
	}
}

/**
 * sift_down - Performs the sift-down operation to maintain the heap property.
 * @arr: The input array representing the binary heap.
 * @start: The index from where to start the sift-down operation.
 * @end: The end index of the heap.
 */
void sift_down(int *arr, int start, int end, size_t size)
{
	int root = start, child, swapIndex;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swapIndex = root;

		if (arr[swapIndex] < arr[child])
			swapIndex = child;
		if (child + 1 <= end && arr[swapIndex] < arr[child + 1])
			swapIndex = child + 1;

		if (swapIndex == root)
			return;

		swap_int(&arr[root], &arr[swapIndex]);
		print_array(arr, size);
		root = swapIndex;
	}
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
