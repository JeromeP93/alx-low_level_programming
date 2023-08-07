#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a linked list, even if it contains a loop.
 * @h: Pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *current, *next;
    size_t count = 0;

    if (h == NULL || *h == NULL)
        return (0);

    current = *h;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        count++;

        if (next >= current)
            break;

        current = next;
    }

    *h = NULL;

    return (count);
}
