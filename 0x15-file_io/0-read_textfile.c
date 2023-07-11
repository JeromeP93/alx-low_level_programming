#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the
 * POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd, res;
char buffer[1024];
ssize_t total_read = 0, total_written = 0;

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

while (((res = read(fd, buffer, sizeof(buffer))) > 0)
&& (total_read < (ssize_t)letters))
{
if (total_read + res > (ssize_t)letters)
res = letters - total_read;

total_written = write(STDOUT_FILENO, buffer, res);
if (total_written == -1)
{
close(fd);
return (0);
}

total_read += res;
}

close(fd);

if ((res == -1) || (total_written != total_read))
return (0);

return (total_read);
}
