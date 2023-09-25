#include "deck.h"

/**
 * compare_cards - func to compare cards
 * @a: pointer
 * @b: pointer
 * Return: 1 or -1
 */

int compare_cards(const void *a, const void *b)
{
	const char *values[] = {"Ace", "2", "3", "4",
		"5", "6", "7", "8",
		"9", "10", "Jack", "Queen",
		"King"};
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;
	int i;

	if (node_a->card->kind < node_b->card->kind)
		return (-1);
	else if (node_a->card->kind > node_b->card->kind)
		return (1);

	for (i = 0; i < 13; i++)
	{
		if (strcmp(node_a->card->value, values[i]) == 0)
			return (-1);
		if (strcmp(node_b->card->value, values[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * sort_deck - function to sort decks
 * @deck: linked list
 */
void sort_deck(deck_node_t **deck)
{
	size_t count = 0, i;
	deck_node_t *current = *deck, **deck_array;

	if (deck == NULL || *deck == NULL)
		return;

	while (current)
	{
		count++;
		current = current->next;
	}

	deck_array = malloc(count * sizeof(deck_node_t *));
	if (deck_array == NULL)
		return;

	current = *deck;
	for (i = 0; i < count; i++)
	{
		deck_array[i] = current;
		current = current->next;
	}

	qsort(deck_array, count, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < count - 1; i++)
	{
		deck_array[i]->next = deck_array[i + 1];
		deck_array[i + 1]->prev = deck_array[i];
	}

	*deck = deck_array[0];
	deck_array[0]->prev = NULL;
	deck_array[count - 1]->next = NULL;
	free(deck_array);
}
