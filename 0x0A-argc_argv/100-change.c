#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Description: This program calculates the minimum number of coins needed to
 * make change for an amount of money specified in cents. It takes one argument
 * which represents the amount of cents to be given back. If the number of
 * arguments is not exactly 1, it prints an error message and returns 1. If the
 * argument is negative, it prints 0. The program assumes that an unlimited
 * number of coins with values 25, 10, 5, 2, and 1 cent can be used.
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
int amount, coins = 0;

if (argc != 2)
{
printf("Error\n");
return (1);
}

amount = atoi(argv[1]);

if (amount < 0)
{
printf("0\n");
return (0);
}

while (amount > 0)
{
if (amount >= 25)
amount -= 25;
else if (amount >= 10)
amount -= 10;
else if (amount >= 5)
amount -= 5;
else if (amount >= 2)
amount -= 2;
else
amount -= 1;

coins++;
}

printf("%d\n", coins);
return (0);
}
