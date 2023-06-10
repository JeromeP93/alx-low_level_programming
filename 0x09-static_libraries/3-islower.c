#include "main.h"

/**
 * _islower - Checks if a character is a lowercase letter.
 * @c: The character to be checked.
 *
 * Return: Returns 1 if c is a lowercase letter, otherwise returns 0.
 */
int _islower(int c)
{
if (c >= 'a' && c <= 'z')
return (1);
else
return (0);
}
