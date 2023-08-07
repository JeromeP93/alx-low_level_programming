#include "main.h"
#include <stdlib.h>

/**
 * get_total_length - calculates the total length of all arguments
 * @ac: number of arguments
 * @av: array of argument strings
 *
 * Return: total length of all arguments
 */
int get_total_length(int ac, char **av)
{
    int total_len = 0;
    int i, j;

    for (i = 0; i < ac; i++)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            total_len++;
            j++;
        }
        total_len++; /* Account for newline character */
    }

    return (total_len);
}

/**
 * copy_arguments - copies the arguments into the concatenated string
 * @ac: number of arguments
 * @av: array of argument strings
 * @str: pointer to the concatenated string
 */
void copy_arguments(int ac, char **av, char *str)
{
    int i, j;
    int k = 0;

    for (i = 0; i < ac; i++)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            str[k] = av[i][j];
            j++;
            k++;
        }
        str[k] = '\n'; /* Append newline character */
        k++;
    }
    str[k] = '\0'; /* Add null terminator at the end */
}

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: number of arguments
 * @av: array of argument strings
 *
 * Return: pointer to a new string containing concatenated arguments
 *         or NULL if ac == 0 or av == NULL or if it fails
 */
char *argstostr(int ac, char **av)
{
    char *str;
    int total_len;

    if (ac == 0 || av == NULL)
        return (NULL);

    total_len = get_total_length(ac, av);

    str = malloc(sizeof(char) * (total_len + 1));
    if (str == NULL)
        return (NULL);

    copy_arguments(ac, av, str);

    return (str);
}
