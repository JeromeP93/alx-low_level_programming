#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - Prints a linked list, even if it contains a loop.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *slow = head;
const listint_t *fast = head;
size_t count = 0;
int loop_detected = 0;

while (slow && fast && fast->next)
{
printf("[%p] %d\n", (void *)slow, slow->n);
slow = slow->next;
fast = fast->next->next;

if (slow == fast)
{
loop_detected = 1;
break;
}
count++;
}

if (loop_detected)
{
slow = head;
while (slow != fast)
{
printf("[%p] %d\n", (void *)slow, slow->n);
slow = slow->next;
fast = fast->next;
}
printf("-> [%p] %d\n", (void *)slow, slow->n);
}
else
{
printf("No loop found\n");
}

return (count);
}
