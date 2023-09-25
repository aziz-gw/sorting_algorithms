#include <stdio.h>
#include "sort.h"

/**
 * swap - Function to swap two elements in an array
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
 * @root: the root
 */
void heapify(int arr[], size_t size, size_t root)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < size && arr[left] > arr[largest])
		largest = left;

	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != root)
	{
		swap(&arr[root], &arr[largest]);
		heapify(arr, size, largest);
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

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		heapify(array, i, 0);
	}
}
