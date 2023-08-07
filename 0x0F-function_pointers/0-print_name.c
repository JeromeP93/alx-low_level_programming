#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: name to be printed
 * @f: pointer to a function that takes a char pointer as parameter
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
    if (name && f)
        f(name);
}
