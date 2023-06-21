#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function
 * @argc: The number of arguments
 * @argv: An array of string arguments
 *
 * Return: 0 on success, 1 if the number of arguments is incorrect,
 *         or 2 if the number of bytes is negative.
 */
int main(int argc, char *argv[])
{
int bytes, i;
unsigned char *main_ptr;

if (argc != 2)
{
printf("Error\n");
return (1);
}

bytes = atoi(argv[1]);
if (bytes < 0)
{
printf("Error\n");
return (2);
}

main_ptr = (unsigned char *)main;

for (i = 0; i < bytes; i++)
{
printf("%02x", *(main_ptr + i));
if (i < bytes - 1)
printf(" ");
}
printf("\n");

return (0);
}
