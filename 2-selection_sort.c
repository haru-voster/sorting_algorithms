/*
 * File: 1-insertion_sort_list.c
 * Auth: haru-voster
 */

#include "sort.h"
/**
 *swapNodes - Swapt two nodes in a doubly linekd list.
 *@list: pointer to the head of the doubly linekd list.
 *@swap1: A pointer to the first node to swap.
 *@swap2: The second node to swap.
 */

void swapNodes(listint_t **list, listint_t **swap1, listint_t *swap2)
{
	(*swap1)->next = swap2->next;
	if (swap2->next != NULL)
		swap2->next->prev = *swap1;
	swap2->prev = (*swap1)->prev;
	swap2->next = *swap1;
	if ((*swap1)->prev != NULL)
		(*swap1)->prev->next = swap2;
	else
		*list = swap2;
	(*swap1)->prev = swap2;
	*swap1 = swap2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the insertion sort algorithm.
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *a, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (a = (*list)->next; a != NULL; a = tmp)
	{
		tmp = a->next;
		insert = a->prev;
		while (insert != NULL && a->n < insert->n)
		{
			swapNodes(list, &insert, a);
			print_list((const listint_t *)*list);
		}
	}
}
