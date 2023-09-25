#include "sort.h"
/**
 * get_maxi - function to get the max of the array
 * @array: the array
 * @size: size of the array
 * Return: max
 */
int get_maxi(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_sort - Perform LSD Radix Sort
 * @array: the array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int exp, max = get_maxi(array, size);

	if (array == NULL || size < 2)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
		print_array(array, size);
	}
}

/**
 * countingSort - Perform counting sort on an array based on a digit
 * @array: The array to be sorted
 * @size: size of the array
 * @exp: Exponent
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int j, count[10] = {0};
	size_t i;

	if (output == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];
	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}
