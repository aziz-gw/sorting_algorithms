#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * enum kind_e - representing the kind of cards.
 * @SPADE:   Spades
 * @HEART:   Hearts
 * @CLUB:    Clubs
 * @DIAMOND: Diamonds
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - representing a playing card.
 * @value: Value of the card (e.g., "Ace", "King")
 * @kind:  Kind of the card (e.g., SPADE, HEART)
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - representing a node in a deck of cards.
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
int compare_cards(const void *a, const void *b);

#endif
