#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at the given index
 * in a linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to be deleted.
 *
 * Return: 1 if it succeeded, or -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *current_node, *previous_node;
    unsigned int i;
    if (head == NULL || *head == NULL)
        return (-1);
    current_node = *head;
    if (index == 0)
    {
        *head = (*head)->next;
        free(current_node);
        return (1);
    }
    previous_node = NULL;

    for (i = 0; i < index; i++)
    {
        if (current_node == NULL)
            return (-1);
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL)
        return (-1);

    previous_node->next = current_node->next;
    free(current_node);
    return (1);
}
