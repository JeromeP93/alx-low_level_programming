#include "main.h"
#include <stdbool.h>
#include <string.h>

/**
 * is_palindrome - Checks if a string is a palindrome.
 * @s: The string to check.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
    int length = strlen(s);

    if (length <= 1)
        return (1);

    if (s[0] != s[length - 1])
        return (0);

    /* Recursive call with the substring excluding the first and last characters */
    return (is_palindrome(s + 1) && is_palindrome(s + length - 1));
}
