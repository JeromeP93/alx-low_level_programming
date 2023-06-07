#include "main.h"
#include <stdio.h>

/**
 * _pow_recursion - Computes the value of x raised to the power of y.
 * @x: The base number.
 * @y: The exponent.
 *
 * Return: The value of x raised to the power of y.
 *         If y is lower than 0, return -1.
 */
int _pow_recursion(int x, int y)
{
if (y < 0) /* Exponent is negative, return -1 to indicate error */
return (-1);

if (y == 0) /* Base case: any number raised to 0 is 1 */
return (1);

return (x * _pow_recursion(x, y - 1)); /* Recursively compute power */
}
