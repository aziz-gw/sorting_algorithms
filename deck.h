#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Enum representing the kind of cards.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * Struct representing a playing card.
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * Struct representing a node in a deck of cards.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif
