#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list.
 * @list: A pointer to a pointer to the head of the list.
 * @node1: The first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *tmp = node2->next;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = tmp;
	node2->next = node1;
	node1->prev = node2;
	if (tmp)
		tmp->prev = node1;
}

/**
 * fwd_pass - Performs the forward pass of the Cocktail Shaker sort.
 * @list: A pointer to a pointer to the head of the list.
 * @start: The starting node for the pass.
 * @end: The ending node for the pass.
 * @swap: A pointer to a flag indicating if any swaps were made.
 */
void fwd_pass(listint_t **list, listint_t *start, listint_t *end, int *swap)
{
	int swapped_local = 0;
	listint_t *current = *list;

	while (current->next != end)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current);
			swapped_local = 1;
		}
		current = current->next;
	}

	*swap = swapped_local;
}

/**
 * back_pass - Performs the backward pass of the Cocktail Shaker sort.
 * @list: A pointer to a pointer to the head of the list.
 * @start: The starting node for the pass.
 * @end: The ending node for the pass.
 * @swap: A pointer to a flag indicating if any swaps were made.
 */
void back_pass(listint_t **list, listint_t *start, listint_t *end, int *swap)
{
	int swapped_local = 0;
	listint_t *current = end;

	while (current->prev != start)
	{
		if (current->n < current->prev->n)
		{
			swap_nodes(list, current);
			swapped_local = 1;
		}
		current = current->prev;
	}

	*swap = swapped_local;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers using the
 * Cocktail Shaker sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end;
	int swapped;

	if (!list || !*list || !(*list)->next)
		return;

	start = NULL;
	end = NULL;
	swapped = 1;

	while (swapped)
	{
		swapped = 0;
		fwd_pass(list, start, end, &swapped);

		if (!swapped)
			break;

		swapped = 0;
		end = *list;
		back_pass(list, start, end, &swapped);
		start = end;
	}
}
