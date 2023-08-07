#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *           containing a copy of the string given as a parameter.
 * @str: the string to be duplicated
 *
 * Return: pointer to the duplicated string, or NULL if insufficient memory
 *         was available or if str is NULL.
 */
char *_strdup(char *str)
{
    char *duplicate;
    unsigned int length = 0;
    unsigned int i;

    if (str == NULL)
        return (NULL);

    /* Calculate the length of the string */
    while (str[length] != '\0')
        length++;

    /* Allocate memory for the duplicate string */
    duplicate = malloc(sizeof(char) * (length + 1));
    if (duplicate == NULL)
        return (NULL);

    /* Copy the string into the duplicate */
    for (i = 0; i <= length; i++)
        duplicate[i] = str[i];

    return (duplicate);
}
