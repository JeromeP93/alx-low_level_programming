#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - Prints a character.
 * @args: The va_list containing the arguments.
 */
void print_char(va_list args)
{
printf("%c", va_arg(args, int));
}

/**
 * print_int - Prints an integer.
 * @args: The va_list containing the arguments.
 */
void print_int(va_list args)
{
printf("%d", va_arg(args, int));
}

/**
 * print_float - Prints a float.
 * @args: The va_list containing the arguments.
 */
void print_float(va_list args)
{
printf("%f", va_arg(args, double));
}

/**
 * print_string - Prints a string.
 * @args: The va_list containing the arguments.
 */
void print_string(va_list args)
{
char *str = va_arg(args, char *);

if (str == NULL)
str = "(nil)";
printf("%s", str);
}

/**
 * print_all - Prints anything based on the given format.
 * @format: A list of types of arguments passed to the function.
 */
void print_all(const char * const format, ...)
{
va_list args;
unsigned int i = 0, j = 0;
char *separator = "";

struct print_format
{
char format;
void (*printer)(va_list);
} valid_formats[] = {
{'c', print_char},
{'i', print_int},
{'f', print_float},
{'s', print_string},
{0, NULL}
};

va_start(args, format);

while (format && format[i])
{
j = 0;
while (valid_formats[j].format != '\0')
{
if (valid_formats[j].format == format[i])
{
printf("%s", separator);
valid_formats[j].printer(args);
separator = ", ";
break;
}
j++;
}
i++;
}

printf("\n");

va_end(args);
}
