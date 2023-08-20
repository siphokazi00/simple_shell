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
static int write_to_fd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

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
static int write_string_to_fd(char *str, int fd)
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

/**
 * _error_puts - Prints an input string to stderr
 * @str: The string to be printed
 *
 * Return: Nothing
 */
void _error_puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		write_to_fd(str[i], STDERR_FD);
		i++;
	}
}

/**
 * _error_putchar - Writes the character c to stderr
 * @c: The character to be written
 *
 * Return: 1 on success, -1 on error.
 */
int _error_putchar(char c)
{
	return (write_to_fd(c, STDERR_FD));
}

/**
 * _putfd - Writes the character c to the given file descriptor
 * @c: The character to be written
 * @fd: The file descriptor to write to
 *
 * Return: 1 on success, -1 on error.
 */
int _putfd(char c, int fd)
{
	return (write_to_fd(c, fd));
}

/**
 * _putsfd - Prints an input string to the specified file descriptor
 * @str: The string to be printed
 * @fd: The file descriptor to write to
 *
 * Return: The number of characters written
 */
int _putsfd(char *str, int fd)
{
	return (write_string_to_fd(str, fd));
}
