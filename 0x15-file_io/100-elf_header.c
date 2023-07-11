#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 64

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
 * print_header_field - Prints the name and value of a header field.
 * @name: The name of the field.
 * @value: The value of the field.
 */
void print_header_field(const char *name, const char *value)
{
printf("%-35s%s\n", name, value);
}

/**
 * elf_header - Displays the information contained in the ELF header of a file.
 * @filename: The name of the file.
 */
void elf_header(const char *filename)
{
int fd, res;
char buffer[BUFFER_SIZE];

if (filename == NULL)
error_exit(98, "Usage: elf_header elf_filename");

fd = open(filename, O_RDONLY);
if (fd == -1)
error_exit(98, "Error: Can't read from file");

if (read(fd, buffer, BUFFER_SIZE) != BUFFER_SIZE)
error_exit(98, "Error: Can't read from file");

print_header_field("Magic:", buffer);
print_header_field("Class:", buffer + 4);
print_header_field("Data:", buffer + 5);
print_header_field("Version:", buffer + 6);
print_header_field("OS/ABI:", buffer + 7);
print_header_field("ABI Version:", buffer + 8);
print_header_field("Type:", buffer + 16);
print_header_field("Entry point address:", buffer + 24);

res = close(fd);
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
if (argc != 2)
error_exit(98, "Usage: elf_header elf_filename");

elf_header(argv[1]);

return (0);
}
