#include "main.h"

/**
 * is_prime_helper - Recursive helper function to check if a number is prime.
 * @n: The number to check.
 * @i: The divisor to check.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime_helper(int n, int i)
{
    if (n <= 1) /* Base case: 0 and 1 are not prime */
        return (0);
    if (n == 2) /* Base case: 2 is prime */
        return (1);
    if (n % i == 0) /* Base case: found a divisor, not prime */
        return (0);
    if (i * i > n) /* Base case: checked up to square root, prime */
        return (1);

    return (is_prime_helper(n, i + 1)); /* Recursive call to check next divisor */
}

/**
 * is_prime_number - Checks if a number is prime.
 * @n: The number to check.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
    return (is_prime_helper(n, 2)); /* Start checking from 2 */
}
