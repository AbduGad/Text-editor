#include "lists.h"
/**
 * free_listint2 - frees a list
 *
 * @head: double pointer to the head of the list
 */
void free_listint2(array **head)
{
	array *holder;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		holder = *head;
		(*head)  = (*head)->Next;
		free(holder->Str);
		free(holder);
		holder = NULL;
	}

}
