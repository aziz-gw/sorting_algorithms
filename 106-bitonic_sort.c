#include "sort.h"
/**
 * bitonic_merge - merge two sec of the array in a bitonic manner
 * @array: The array to be sorted
 * @size: the size
 * @beg: index to start
 * @seq: size of sequence
 * @dir: sorting asc pr desc
 */
void bitonic_merge(int *array, size_t size, size_t beg, size_t seq, int dir)
{
	size_t half, i;
	int temp;

	if (seq > 1)
	{
		half = seq / 2;
		for (i = beg; i < beg + half; i++)
		{
			if ((array[i] > array[i + half]) == dir)
			{
				temp = array[i];
				array[i] = array[i + half];
				array[i + half] = temp;
			}
		}
		bitonic_merge(array, size, beg, half, dir);
		bitonic_merge(array, size, beg + half, half, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sort a bitonic sequence
 * @array: The array to be sorted
 * @size: the size
 * @dir: sorting asc pr desc
 * @beg: the start
 * @seq: sequence
 */
void bitonic_sort_recursive(int *array, size_t size, size_t beg, size_t seq, int dir)
{
	size_t half;
	char *direction;

	if (seq > 1)
	{
		if (dir == 1)
			direction = "UP";
		else
			direction = "DOWN";

		printf("Merging [%lu/%lu] (%s):\n", seq, size, direction);
		print_array(array + beg, seq);
		half = seq / 2;
		bitonic_sort_recursive(array, size, beg, half, 1);
		bitonic_sort_recursive(array, size, beg + half, half, 0);
		bitonic_merge(array, size, beg, seq, dir);
		printf("Result [%lu/%lu] (%s):\n", seq, size, direction);
		print_array(array + beg, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers using
 * the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: the size
 */
void bitonic_sort(int *array, size_t size)
{
	int dir = 1; /* ascending */

	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, size, 0, size, dir);
}
