#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0;
    const listint_t *current = head;
    const listint_t *loop_node = NULL;

    while (current)
    {
        printf("[%p] %d\n", (void *)current, current->n);
        count++;
        current = current->next;

        /* Check for a loop */
        if (current == loop_node)
        {
            printf("-> [%p] %d\n", (void *)current, current->n);
            break;
        }

        /* Set loop_node if it's NULL */
        if (loop_node == NULL)
            loop_node = head;

        if (loop_node)
            loop_node = loop_node->next;

        if (current == NULL || loop_node == NULL)
            continue;

        if (current == loop_node)
        {
            printf("-> [%p] %d\n", (void *)current, current->n);
            break;
        }
    }

    return (count);
}
