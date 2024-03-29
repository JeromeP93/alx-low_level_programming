#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2D array of integers
 * @width: the width of the grid
 * @height: the height of the grid
 *
 * Return: pointer to the 2D array,
 *         or NULL on failure or invalid width/height.
 */
int **alloc_grid(int width, int height)
{
    int **grid;
    int i, j;

    if (width <= 0 || height <= 0)
        return (NULL);

    /* Allocate memory for the rows */
    grid = (int **)malloc(sizeof(int *) * height);
    if (grid == NULL)
        return (NULL);

    /* Allocate memory for the columns */
    for (i = 0; i < height; i++)
    {
        grid[i] = (int *)malloc(sizeof(int) * width);
        if (grid[i] == NULL)
        {
            /* Free previously allocated memory on failure */
            for (j = 0; j < i; j++)
                free(grid[j]);
            free(grid);
            return (NULL);
        }
    }

    /* Initialize each element to 0 */
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            grid[i][j] = 0;
        }
    }

    return (grid);
}
