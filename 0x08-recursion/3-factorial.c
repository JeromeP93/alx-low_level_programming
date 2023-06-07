#include "main.h"
#include <stdio.h>

/**
 * factorial - Computes the factorial of a number.
 * @n: The number to compute the factorial of.
 *
 * Return: The factorial of n, or -1 if n is negative.
 */
int factorial(int n)
{
if (n < 0) /* Negative number, return -1 to indicate error */
return (-1);

if (n == 0) /* Base case: factorial of 0 is 1 */
return (1);

return (n * factorial(n - 1)); /* Recursively compute factorial */
}
