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

	b->Str = copy;
	if (b->Str == NULL)
	{
		free(b);
		return (NULL);
	}

	while (str[len])
		len++;

	b->Next = NULL;
	b->LineLen = len;
	if (*head == NULL)
	{
		*head = b;
		b->Index = 0;
		return (b);
	}

	temp = *head;
	while (temp->Next != NULL)
	{
		temp = temp->Next;
	}

	b->Index = temp->Index + 1;	
	temp->Next = b;
	return (b);
}
