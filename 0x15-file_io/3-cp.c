#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

#define BUFFER_SIZE 1024

void display_usage_error(const char *program_name);
void display_read_error(const char *filename);
void display_write_error(const char *filename);
void display_close_error(int fd);
int open_source_file(const char *filename);
int open_destination_file(const char *filename);
void copy_file_content(int source_fd, int destination_fd);
void close_file(int fd);

/**
 * main - Entry point. Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or the corresponding error code.
 */
int main(int argc, char *argv[])
{
int source_fd, destination_fd;

if (argc != 3)
{
display_usage_error(argv[0]);
exit(97);
}

source_fd = open_source_file(argv[1]);
if (source_fd == -1)
{
display_read_error(argv[1]);
exit(98);
}

destination_fd = open_destination_file(argv[2]);
if (destination_fd == -1)
{
display_write_error(argv[2]);
exit(99);
}

copy_file_content(source_fd, destination_fd);

close_file(source_fd);
close_file(destination_fd);

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
* display_read_error - Displays the read error message.
* @filename: The name of the file.
*/
void display_read_error(const char *filename)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
}

/**
* display_write_error - Displays the write error message.
* @filename: The name of the file.
*/
void display_write_error(const char *filename)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
}

/**
* display_close_error - Displays the close error message.
* @fd: The file descriptor.
*/
void display_close_error(int fd)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
}

/**
* open_source_file - Opens the source file for reading.
* @filename: The name of the file.
*
* Return: The file descriptor, or -1 on failure.
*/
int open_source_file(const char *filename)
{
int fd = open(filename, O_RDONLY);
return (fd);
}

/**
* open_destination_file - Opens the destination file for writing.
* @filename: The name of the file.
*
* Return: The file descriptor, or -1 on failure.
*/
int open_destination_file(const char *filename)
{
int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
return (fd);
}

/**
* copy_file_content - Copies the content from source_fd to destination_fd.
* @source_fd: The source file descriptor.
* @destination_fd: The destination file descriptor.
*/
void copy_file_content(int source_fd, int destination_fd)
{
char buffer[BUFFER_SIZE];
ssize_t bytes_read, bytes_written;

while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(destination_fd, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
display_write_error("destination file");
exit(99);
}
}

if (bytes_read == -1)
{
display_read_error("source file");
exit(98);
}
}

/**
* close_file - Closes the file associated with the file descriptor.
* @fd: The file descriptor.
*/
void close_file(int fd)
{
if (close(fd) == -1)
{
display_close_error(fd);
exit(100);
}
}
