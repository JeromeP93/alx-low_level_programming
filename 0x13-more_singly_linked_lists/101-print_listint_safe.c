#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a linked list, even if it contains a loop.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *curr = head;
size_t count = 0;

while (curr)
{
printf("[%p] %d\n", (void *)curr, curr->n);
count++;

if (curr > curr->next)
{
printf("-> [%p] %d\n", (void *)curr->next, curr->next->n);
break;
}

curr = curr->next;
}

return (count);
}
