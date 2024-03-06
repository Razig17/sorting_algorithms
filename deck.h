#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>




/**
 * enum kind_e - Represents the suits of playing cards.
 * @SPADE: The spade suit.
 * @HEART: The heart suit.
 * @CLUB: The club suit.
 * @DIAMOND: The diamond suit.
 *
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
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

void print_deck(const deck_node_t *deck);
deck_node_t *init_deck(const card_t cards[52]);

void sort_deck(deck_node_t **deck);
int swap(deck_node_t *prev, deck_node_t *tmp, deck_node_t **deck);
int value(deck_node_t *node);

#endif /* DECK_H*/
