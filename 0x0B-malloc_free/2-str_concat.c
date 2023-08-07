#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: pointer to the concatenated string,
 *         or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
    char *concatenated;
    unsigned int len1 = 0, len2 = 0;
    unsigned int i, j;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    /* Calculate the lengths of s1 and s2 */
    while (s1[len1] != '\0')
        len1++;
    while (s2[len2] != '\0')
        len2++;

    /* Allocate memory for the concatenated string */
    concatenated = malloc(sizeof(char) * (len1 + len2 + 1));
    if (concatenated == NULL)
        return (NULL);

    /* Copy s1 to the concatenated string */
    for (i = 0; i < len1; i++)
        concatenated[i] = s1[i];

    /* Copy s2 to the concatenated string */
    for (j = 0; j < len2; j++)
        concatenated[i + j] = s2[j];

    concatenated[i + j] = '\0'; /* Add null terminator */

    return (concatenated);
}
