#include <stdio.h>
#include "sort.h"

/**
 * swap - swapfunc
 * @a: a pointer
 * @b: a pointer
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * heapify - Function to heapify a subtree rooted at given index
 * @arr: an array
 * @size: size of the array
 * @t_be: the base
 * @root: the root
 */
void heapify(int arr[], size_t size, size_t t_be, size_t root)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < t_be && arr[left] > arr[largest])
		largest = left;

	if (right < t_be && arr[right] > arr[largest])
		largest = right;

	if (largest != root)
	{
		swap(&arr[root], &arr[largest]);
		print_array(arr, size);
		heapify(arr, size, t_be, largest);
	}
}

/**
 * heap_sort - a function that sorts an array of integers
 * in ascending order using the Heap sort algorithm
 * @array: the array
 * @size: size
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		heapify(array, size, size, i);
	}

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
