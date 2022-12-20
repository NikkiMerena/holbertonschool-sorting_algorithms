#include "sort.h"

/**
 * _swap - swaps 2 elements in an list
 * @head: head of list
 * @a: node
 * @b: node
 */

void _swap(listint_t *a, listint_t *b, listint_t **head)
{
	listint_t *aux1 = NULL, *aux2 = NULL;

	if (a == NULL || b == NULL)
		return;

	aux1 = a->prev;
	aux2 = b->next;

	/* adjacent nodes */
	if (aux1)
		aux1->next = b;
	if (aux2)
		aux2->prev = a;
	a->next = aux2;
	a->prev = b;
	b->next = a;
	b->prev = aux1;
	if (aux1 == NULL)
		*head = b;
}

/**
 * insertion_sort_list  -  function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly liked list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;
	int aux;

	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
	{
		return;
	}

	head = *list;

	while (head)
	{
		prev = head->prev;
		aux = head->n;

		while (prev && prev->n > aux)
		{
			_swap(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}
