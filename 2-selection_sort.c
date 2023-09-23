#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
 * @a: the first integer to swap
 * @b: the second integer to swap
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: an array of integers
 * @size: the size of the array
 *
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	int *min_int;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_int = array + i;
		for (j = i + 1; j < size; j++)
			if (array[j] < *min_int)
				min_int = (array + j);
			else
				min_int = min_int;

		if ((array + i) != min_int)
		{
			swap_ints(array + i, min_int);
			print_array(array, size);
		}
	}
}
