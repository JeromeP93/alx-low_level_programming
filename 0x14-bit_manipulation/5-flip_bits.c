#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to flip to get
 * from one number to another.
 * @n: Unsigned long int number.
 * @m: Unsigned long int number.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int diff = n ^ m;
    unsigned int count = 0;

    while (diff > 0)
    {
        if (diff & 1)
            count++;
        diff >>= 1;
    }

    return (count);
}
