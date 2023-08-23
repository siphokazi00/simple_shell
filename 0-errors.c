#include "shell.h"

#define STDERR_FD 2
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/**
 * write_to_fd - Writes the given char to the specified file descriptor
 * @c: The character to be written
 * @fd: The file descriptor to write to
 *
 * Return: 1 on success, -1 on error.
 */
int write_to_fd(char c, int fd)
{
	int i = 0;
	char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || c == '\n' || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * write_string_to_fd - Prints an input string to the specified file descriptor
 * @str: The string to be printed
 * @fd: The file descriptor to write to
 *
 * Return: The number of chars written
 */
int write_string_to_fd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += write_to_fd(*str++, fd);
	}
	return (i);
}
