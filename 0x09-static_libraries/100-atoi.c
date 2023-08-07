#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: Pointer to the string to be converted.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    /* Handle the sign of the number */
    if (s[0] == '-')
    {
        sign = -1;
        i++;
    }

    /* Convert each digit to integer until a non-digit character is encountered */
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result = result * 10 + (s[i] - '0');
            i++;
        }
        else
        {
            /* Stop converting if a non-digit character is encountered */
            break;
        }
    }

    return (sign * result);
}
