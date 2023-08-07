#include "main.h"

/**
 * _strcmp - Compares two strings.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: Integer less than, equal to, or greater than zero if s1 is found,
 *         respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return ((s1[i] - s2[i]));
        i++;
    }

    /* Check if one string has reached its null terminator before the other */
    if (s1[i] == '\0' && s2[i] != '\0')
        return ((-s2[i]));
    else if (s1[i] != '\0' && s2[i] == '\0')
        return ((s1[i]));

    return (0); /* Both strings are equal */
}
