#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list.
 * @head: pointer to a pointer to the head of the linked list.
 * @node1: pointer to the first node to be swapped.
 * @node2: pointer to the second node to be swapped.
 */

void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascendind order using the insertion sort algorithm; prints the list
 * after each time the two nodes are swaped
 *
 * @list: a pointer to the head of a doubly-linked list
 *
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		insert = current->prev;
		while (insert != NULL && current->n < insert->n)
		{
			swap_nodes(list, &insert, current);
			print_list((const listint_t *)*list);
		}
	}
}
