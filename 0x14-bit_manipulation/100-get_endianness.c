#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
unsigned int value = 1;
char *ptr = (char *)&value;

if (*ptr)
return (1);  /* Little Endian */
else
return (0);  /* Big Endian */
}
