#include "sort.h"

/**
 * insertion_sort_list - Sorts a DLL using Insertion sort
 * @list: A pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *behind, *ahead;
	listint_t *head;

	if (!list || !*list || !(*list)->next)
		return;

	head = *list; /* Reference to the head. */
	curr = head->next; /* Start with second node. */

	while (curr)
	{
		ahead = curr->next;
		behind = curr->prev;

		while (behind && behind->n > curr->n)
		{
			/* Update the next pointer of the node behind to skip curr. */
			behind->next = curr->next;
			/* Update the prev pointer of the node after curr, if it exists*/
			if (curr->next)
			curr->next->prev = behind;

			/*Update the prev and next pointers of curr to move it behind.*/
			curr->prev = behind->prev;
			curr->next = behind;

			/* Update the next pointer of node before behind to point to curr*/
			if (behind->prev)
				behind->prev->next = curr;
			else
				*list = curr;

			behind->prev = curr;
			behind = curr->prev;
			print_list(*list);

		}
		curr = ahead;
	}
}
