#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: Pointer to the head of the list_t list
 * @str: String added to the list_t list
 *
 * Return: Address of the new element, or NULL if it failed
 */
array *add_node_end(array **head, const char *str)
{
	array *b, *temp;
	char *copy;
	int len = 0;

	copy = strdup(str);
	if (head == NULL)
		return (NULL);
	b = (array *)malloc(sizeof(array));
	if (b == NULL)
		return (NULL);
	b->str = copy;
	if (b->str == NULL)
	{
		free(b);
		return (NULL);
	}
	while (str[len])
		len++;
	b->next = NULL;
	b->len = len;
	if (*head == NULL)
	{
		*head = b;
		return (b);
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = b;
	return (b);
}
