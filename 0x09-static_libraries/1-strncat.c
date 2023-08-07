#include "main.h"

/**
 * _strncat - Concatenates two strings, using at most n bytes from src.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * @n: Maximum number of bytes to be used from src.
 *
 * Return: Pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
    int dest_len = 0;
    int i;

    /* Find the length of the destination string */
    while (dest[dest_len] != '\0')
        dest_len++;

    /* Concatenate the source string to the destination string, up to n bytes */
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[dest_len++] = src[i];

    dest[dest_len] = '\0'; /* Add the null terminator at the end */

    return (dest);
}
