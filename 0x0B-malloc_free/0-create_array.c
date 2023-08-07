#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of characters and
 * initializes it with a specific character.
 * @size: The size of the array to create.
 * @c: The character to initialize the array with.
 *
 * Return: On success, returns a pointer to the newly allocated
 * and initialized array.
 *         If size is 0 or if the allocation fails, returns NULL.
 */
char *create_array(unsigned int size, char c)
{
    char *array;

    if (size == 0)
        return (NULL);

    array = malloc(sizeof(char) * size);
    if (array == NULL)
        return (NULL);

    {
        unsigned int i;

        for (i = 0; i < size; i++)
            array[i] = c;
    }

    return (array);
}
