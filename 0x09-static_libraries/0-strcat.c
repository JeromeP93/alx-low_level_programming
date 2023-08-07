#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
    int dest_len = 0;
    int i;

    /* Find the length of the destination string */
    while (dest[dest_len] != '\0')
        dest_len++;

    /* Concatenate the source string to the destination string */
    for (i = 0; src[i] != '\0'; i++)
        dest[dest_len++] = src[i];

    dest[dest_len] = '\0'; /* Add the null terminator at the end */

    return (dest);
}
