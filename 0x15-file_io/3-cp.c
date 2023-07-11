#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error_exit - Prints an error message and exits with the specified code.
 * @code: The exit code.
 * @message: The error message to print.
 */
void error_exit(int code, const char *message)
{
dprintf(STDERR_FILENO, "%s\n", message);
exit(code);
}

/**
 * cp - Copies the content of one file to another file.
 * @file_from: The name of the source file.
 * @file_to: The name of the destination file.
 */
void cp(const char *file_from, const char *file_to)
{
int fd_from, fd_to, res;
char buffer[BUFFER_SIZE];
ssize_t n_read, n_written;

if (file_from == NULL)
error_exit(97, "Usage: cp file_from file_to");

fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
error_exit(98, "Error: Can't read from file");

fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
error_exit(99, "Error: Can't write to file");

while ((n_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
n_written = write(fd_to, buffer, n_read);
if (n_written == -1)
error_exit(99, "Error: Can't write to file");

if (n_written != n_read)
error_exit(99, "Error: Can't write to file");
}

if (n_read == -1)
error_exit(98, "Error: Can't read from file");

res = close(fd_from);
if (res == -1)
error_exit(100, "Error: Can't close fd");

res = close(fd_to);
if (res == -1)
error_exit(100, "Error: Can't close fd");
}

/**
 * main - Entry point.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char **argv)
{
if (argc != 3)
error_exit(97, "Usage: cp file_from file_to");

cp(argv[1], argv[2]);

return (0);
}
