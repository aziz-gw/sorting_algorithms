#include "sort.h"

/**
 * merge_subarray - sorts a subarray of integers
 * @subarray: a subarray of an array of integers to sort
 * @buff: a buffer to store the sorted subarray
 * @front: the front index of the array
 * @mid: the middle index of the array
 * @back: the back index of the array
 */

void merge_subarray(int *subarray, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + front, mid - front);

	printf("[right]: ");
	print_array(subarray + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];

	for (; i < mid; i++)
		buff[k++] = subarray[i];
	for (; j < back; j++)
		buff[k++] = subarray[j];
	for (i = front, k = 0; i < back; i++)
		subarray[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarray + front, back - front);
}

/**
 * mergesort_recursive - implements the merge sort algorithm using
 * recursion
 * @subarray: a subarray of an array of integers to sort
 * @buff: a buffer to store the sorted subarray
 * @front: the front index of the subarray
 * @back: the back index of the subarray
 */
void mergesort_recursive(int *subarray, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		mergesort_recursive(subarray, buff, front, mid);
		mergesort_recursive(subarray, buff, mid, back);
		merge_subarray(subarray, buff, front, mid, back);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the merge sort algorithm
 * @array: an array to be sorted
 * @size: the size of an array
 *
 * Return: Nothing
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	mergesort_recursive(array, buff, 0, size);

	free(buff);
}
