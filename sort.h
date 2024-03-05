#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);
void quick_sort_recursion(int array[], size_t lo, size_t hi, size_t size);
size_t lomuto_pivot(int array[], size_t lo, size_t hi, size_t size);

void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
int swap(listint_t *prev, listint_t *tmp, listint_t **list);

void counting_sort(int *array, size_t size);

void merge_sort(int *array, size_t size);
void split(int *array, int *copy, size_t first, size_t last);
void merge(int *array, int *copy, size_t first, size_t mid, size_t last);
void copy_arr(int *dest, int *src, size_t size);

void heap_sort(int *array, size_t size);
void swap_int(int *a, int *b);
void heapify(int *array, size_t size);
void sift_down(int arr[], int start, int end, size_t size);

void radix_sort(int *array, size_t size);
void bubble(int *array, size_t size, size_t exp);

void merge_b(int arr[], size_t low, size_t count, int direction);
void bitonic(int arr[], size_t low, size_t count, size_t size, int direction);
void bitonic_sort(int *array, size_t size);

void quick_sort_hoare(int *array, size_t size);
void hoare_pivot(int *arr, int low, int high, size_t size);
#endif /* SORT_H*/
