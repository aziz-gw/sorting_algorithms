#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int low, int high);
void hoare_sort(int *array, size_t size, int low, int high);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * hoare_partition - Orders a subset of an array of integers
 *                   according to the Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
    int pivot, above, below;

    pivot = array[low];
    above = low - 1;
    below = high + 1;

    while (1)
    {
        do
        {
            above++;
        } while (array[above] < pivot);

        do
        {
            below--;
        } while (array[below] > pivot);

        if (above >= below)
            return below;
        swap_ints(array + above, array + below);
        print_array(array, size);
    }
}

/**
 * hoare_sort - Implements the quicksort algorithm using the Hoare scheme.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 */
void hoare_sort(int *array, size_t size, int low, int high)
{
    int part;

    if (low < high)
    {
        part = hoare_partition(array, size, low, high);
        hoare_sort(array, size, low, part);
        hoare_sort(array, size, part + 1, high);
	print_array(array, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the quicksort algorithm (Hoare scheme).
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    hoare_sort(array, size, 0, size - 1);
}
