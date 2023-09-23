#include "sort.h"

/**
 * swap_ints - swaps two integers in an array.
 * @a: the first integer to swap.
 * @b: the second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - partitions the array using Lomuto partition scheme
 * @array: the array to be partitioned
 * @size: the size of the array.
 * @low: the lower index of the partition
 * @high: the higher index of the partition
 *
 * Return: the index of the pivot element after the partition
 */

int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot, right, left;

	pivot = array + high;
	for (right = left = low; left < high; left++)
	{
		if (array[left] < *pivot)
		{
			if (right < left)
			{
				swap_ints(array + left, array + right);
				print_array(array, size);
			}
			right++;
		}
	}

	if (array[right] > *pivot)
	{
		swap_ints(array + right, pivot);
		print_array(array, size);
	}

	return (right);
}

/**
 * quicksort_recursive - Implements the quicksort algorithm using
 * recursion
 * @array: the array be sorted
 * @size: the size of the array
 * @low: the lower index of the partition
 * @high: the higher index of the partition
 *
 * Return: nothing
 */

void quicksort_recursive(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = lomuto_partition(array, size, low, high);
		quicksort_recursive(array, size, low, part - 1);
		quicksort_recursive(array, size, part + 1, high);
	}
}

/**
 * quick_sort - sort an array of integers in ascending order
 * using the quicksort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, size, 0, size - 1);
}
