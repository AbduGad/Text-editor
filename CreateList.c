#include "lists.h"

array *CreateList(array **head)
{
	if (head == NULL)
		return (NULL);

	*head = (array *)malloc(sizeof(array));
	if (*head == NULL)
		return (NULL);

	(*head)->LineLen = 0;
	(*head)->Str = NULL;
	(*head)->Next = NULL;

	// *head = (array *)malloc(sizeof(array));
	// if (*head == NULL)
	// 	return (NULL);
}