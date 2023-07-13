#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

#define BUFFER_SIZE 1024

void display_usage_error(const char *program_name);
void display_error(const char *message);
int open_file(const char *filename, int flags, mode_t mode);
void copy_file(const char *source_filename, const char *destination_filename);

/**
 * main - Entry point. Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or the corresponding error code.
 */
int main(int argc, char *argv[])
{
if (argc != 3)
{
display_usage_error(argv[0]);
return (97);
}

copy_file(argv[1], argv[2]);

return (0);
}

/**
 * display_usage_error - Displays the usage error message.
 * @program_name: The name of the program.
 */
void display_usage_error(const char *program_name)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", program_name);
}

/**
 * display_error - Displays the error message.
 * @message: The error message.
 */
void display_error(const char *message)
{
dprintf(STDERR_FILENO, "Error: %s\n", message);
}

/**
 * open_file - Opens a file with the specified flags and mode.
 * @filename: The name of the file.
 * @flags: The flags to use for opening the file.
 * @mode: The mode to use if creating the file.
 *
 * Return: The file descriptor, or -1 on failure.
 */
int open_file(const char *filename, int flags, mode_t mode)
{
int fd = open(filename, flags, mode);
if (fd == -1)
display_error(filename);
return (fd);
}

/**
 * copy_file - Copies the content from source file to destination file.
 * @source_filename: The name of the source file.
 * @destination_filename: The name of the destination file.
 */
void copy_file(const char *source_filename, const char *destination_filename)
{
int source_fd, destination_fd;
ssize_t bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

source_fd = open_file(source_filename, O_RDONLY, 0);
if (source_fd == -1)
exit(98);

destination_fd = open_file(destination_filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (destination_fd == -1)
{
close(source_fd);
exit(99);
}

while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(destination_fd, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
display_error(destination_filename);
exit(99);
}
}

if (bytes_read == -1)
{
display_error(source_filename);
exit(98);
}

if (close(source_fd) == -1)
{
display_error("Can't close source file");
exit(100);
}

if (close(destination_fd) == -1)
{
display_error("Can't close destination file");
exit(100);
}
}
