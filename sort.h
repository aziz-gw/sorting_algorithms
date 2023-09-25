#ifndef SORT_H
#define SORT_H

#include <stddef.h>
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

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void swap_ints(int *a, int *b);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void sort_deck(deck_node_t **deck);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

/* Utility functions */
void swap_ints(int *a, int *b);
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2);
int lomuto_partition(int *array, size_t size, int low, int high);
void quicksort_recursive(int *array, size_t size, int low, int high);
int get_max(int *array, int size);
void merge_subarray(int *subarray, int *buff, size_t front, size_t mid,
		size_t back);
void mergesort_recursive(int *subarray, int *buff, size_t front, size_t back);
void swap(int *a, int *b);
void heapify(int arr[], size_t size, size_t t_be, size_t root);
int get_maxi(int *array, size_t size);
void countingSort(int *array, size_t size, int exp);

#endif
