#include "sort.h"
#include <stdbool.h>

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
 * bubble_sort - prints the array after each swap
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len;

	bool track_swap = false;

	if (array == NULL || size < 2)
		return;

	while (track_swap == false)
	{
		track_swap = true;
		len = size;
		/* Iterate through the array from the first, second ... to */
		 /* the last element */
		for (i = 0; i < (len - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, ((array + i) + 1));
				/* Prints the array after each swap */
				print_array(array, size);
				track_swap = false;
			}
		}
		len--;
	}
}

