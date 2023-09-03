#ifndef LISTS_H
#define LISTS_H

#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h> /* ncurses.h includes stdio.h */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

typedef struct single_linked_list
{
	struct single_linked_list *Next;
	int Index;
	int LineLen;
	char *Str;
} array;

array *add_node_end(array **head, const char *str);
array *CreateList(array **head);
void free_listint2(array **head);


#endif