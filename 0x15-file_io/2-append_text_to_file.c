#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The text content to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int fd, bytes_written;
size_t text_len = 0;
struct stat st;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);

if (text_content != NULL)
{
while (text_content[text_len] != '\0')
text_len++;

bytes_written = write(fd, text_content, text_len);
if (bytes_written == -1 || (size_t)bytes_written != text_len)
{
close(fd);
return (-1);
}
}

close(fd);

if (stat(filename, &st) == 0)
return (1);

return (-1);
}
