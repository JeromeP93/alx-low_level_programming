#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - Prints anything based on the given format.
 * @format: A list of types of arguments passed to the function.
 */
void print_all(const char * const format, ...)
{
va_list args;
unsigned int i = 0;
char *separator = "";
char curr_char;

va_start(args, format);

while (format && format[i])
{
curr_char = format[i];

if (curr_char == 'c')
printf("%s%c", separator, va_arg(args, int));
else if (curr_char == 'i')
printf("%s%d", separator, va_arg(args, int));
else if (curr_char == 'f')
printf("%s%f", separator, va_arg(args, double));
else if (curr_char == 's')
{
char *str_arg = va_arg(args, char *);
if (str_arg == NULL)
str_arg = "(nil)";
printf("%s%s", separator, str_arg);
}

separator = ", ";
i++;
}

printf("\n");

va_end(args);
}
