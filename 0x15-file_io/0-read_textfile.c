#include "main.h"
#include <fcntl.h>
#include <unistd.h>

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
int fd;
ssize_t n_read;
char buffer[1024];

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

n_read = read(fd, buffer, letters);
if (n_read == -1)
{
close(fd);
return (0);
}

if (write(STDOUT_FILENO, buffer, n_read) == -1)
{
close(fd);
return (0);
}

close(fd);
return (n_read);
}
