#include "deck.h"

/**
 * sort_deck - Sorts a deck of cards using Cocktail shaker sort algorithm
 *
 * @deck: The deck to be sorted
 *
 */

void sort_deck(deck_node_t **deck)
{

	int swaping = 1;
	deck_node_t *tmp;

	if (deck == NULL || *deck == NULL)
		return;
	tmp = *deck;

	while (swaping == 1)
	{
		swaping = 0;
		while (tmp->next && tmp)
		{

			if (tmp->card->kind > tmp->next->card->kind ||
			    (value(tmp) > value(tmp->next) &&
			     tmp->card->kind == tmp->next->card->kind))

				swaping = swap(tmp, tmp->next, deck);
			else
				tmp = tmp->next;
		}

		while (tmp->prev && tmp)
		{
			if (tmp->card->kind < tmp->prev->card->kind ||
			    (value(tmp) < value(tmp->prev) &&
			     tmp->card->kind == tmp->prev->card->kind))

				swaping = swap(tmp->prev, tmp, deck);
			else
				tmp = tmp->prev;
		}
	}
}

/**
 * swap - swaps two deck cards nodes
 *
 * @prev: A pointer to the node of the first card
 * @tmp: A pointer to the node of the second card
 * @deck: A pointer to a pointer to the head node of a deck of cards
 * Return: Returnes 1 or 0 if it fails
 *
 */

int swap(deck_node_t *prev, deck_node_t *tmp, deck_node_t **deck)
{
	if (prev == NULL || tmp == NULL || deck == NULL)
		return (0);

	prev->next = tmp->next;
	if (prev->next)
		prev->next->prev = prev;
	tmp->prev = prev->prev;
	if (tmp->prev)
		tmp->prev->next = tmp;
	prev->prev = tmp;
	tmp->next = prev;
	prev = tmp->prev;
	if (tmp->prev == NULL)
		*deck = tmp;
	return (1);
}

/**
 * value - Find the value of a card
 * @node: A pointer to the node of the card
 *
 * Return: The value of a card
 */
int value(deck_node_t *node)
{
	if (strcmp(node->card->value, "Ace") == 0)
		return (1);
	if (*(node->card->value) > 49 && *(node->card->value) < 58
	&& *((node->card->value) + 1) == '\0')
		return (*(node->card->value) - 48);
	if (strcmp(node->card->value, "10") == 0)
		return (10);
	if (strcmp(node->card->value, "Jack") == 0)
		return (11);
	if (strcmp(node->card->value, "Queen") == 0)
		return (12);
	return (13);
}
