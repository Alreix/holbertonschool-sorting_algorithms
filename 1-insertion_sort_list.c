#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion Sort
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			listint_t *prev = temp->prev;
			listint_t *next = temp->next;

			if (prev->prev != NULL)
				prev->prev->next = temp;
			temp->prev = prev->prev;

			temp->next = prev;
			prev->prev = temp;
			prev->next = next;
			if (next != NULL)
				next->prev = prev;

			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);
		}
		current = current->next;
	}
}
