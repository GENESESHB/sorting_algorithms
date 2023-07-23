#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @head:pointer to the head of the doubly-linked list.
 * @node1:pointer to the first node to swap.
 * @node2:second node to swap.
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
	(*node1) = node2->prev;
}



/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in order
 * @list: A pointer of  head  the doubly linked list.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cle, *insert, *tp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (cle = (*list)->next; cle != NULL; cle = tp)
	{
		tp = cle->next;
		insert = cle->prev;
		while (insert != NULL && cle->n < insert->n)
		{
			swap_nodes(list, &insert, cle);
			print_list((const listint_t *)*list);
		}

	}


}
