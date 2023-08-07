#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Description: This program adds positive numbers provided as command-line
 * arguments and prints the result. If no number is passed, it prints 0. If any
 * of the numbers contain symbols that are not digits, it prints an error
 * message and returns 1.
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
    int i, num, sum;

    if (argc < 2)
    {
        printf("0\n");
        return (0);
    }

    sum = 0;
    for (i = 1; i < argc; i++)
    {
        char *arg = argv[i];
        int j;

        for (j = 0; arg[j] != '\0'; j++)
        {
            if (arg[j] < '0' || arg[j] > '9')
            {
                printf("Error\n");
                return (1);
            }
        }

        num = atoi(arg);
        if (num > 0)
            sum += num;
    }

    printf("%d\n", sum);
    return (0);
}
