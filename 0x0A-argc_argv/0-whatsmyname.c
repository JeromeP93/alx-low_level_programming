#include <stdio.h>

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Description: This program prints its name, followed by a new line.
 * If you rename the program, it will print the new name without having
 * to compile it again. The program utilizes the `argv[0]` command-line
 * argument to access the program's name, including the path.
 *
 * Return: 0 on success
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
printf("%s\n", argv[0]);
return (0);
}
