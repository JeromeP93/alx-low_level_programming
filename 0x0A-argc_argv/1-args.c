#include <stdio.h>

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Description: This program prints the number of arguments passed into it.
 * The value printed is equal to `argc - 1`, as `argc` includes the program
 * name itself as the first argument. The program utilizes the `argc` parameter
 * to determine the count of additional arguments passed to it.
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
    printf("%d\n", argc - 1);
    return (0);
}
