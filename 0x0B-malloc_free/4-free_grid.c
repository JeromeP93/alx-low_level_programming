#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2D grid previously created by alloc_grid
 * @grid: pointer to the 2D grid to be freed
 * @height: height of the grid
 *
 * Return: void
 */
void free_grid(int **grid, int height)
{
    int i;

    if (grid == NULL || height <= 0)
        return;

    /* Free each row */
    for (i = 0; i < height; i++)
    {
        free(grid[i]);
    }

    /* Free the grid itself */
    free(grid);
}
