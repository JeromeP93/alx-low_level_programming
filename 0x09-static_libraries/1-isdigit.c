#include "main.h"

/**
 * _isdigit - Checks if a character is a digit.
 * @c: The character to be checked.
 *
 * Return: Returns 1 if c is a digit, otherwise returns 0.
 */
int _isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}
