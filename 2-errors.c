#include "shell.h"

/**
 * _erratoi - Converts a string to an integer.
 * @str: The string to be converted.
 *
 * Return: The converted number if valid,
 *         -1 on error.
 */
int _erratoi(char *str)
{
	int i = 0;
	unsigned long int result = 0;

	if (*str == '+')
		str++;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - Prints an error message.
 * @info: The parameter and return info struct.
 * @estr: String containing specified error type.
 *
 * Return: Nothing.
 */
void print_error(info_t *info, char *estr)
{
	fprintf(stderr, "%s: %d: %s: %s", info->fname, info->line_count,
			info->argv[0], estr);
}

/**
 * print_d - Prints a decimal number.
 * @input: The input number.
 * @fd: The file descriptor to write to.
 *
 * Return: Number of characters printed.
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = (fd == STDERR_FILENO) ? _error_putchar : _putchar;
	int count = 0;
	unsigned int _abs_ = (input < 0) ? -input : input;
	unsigned int current = _abs_;

	if (input < 0)
	{
		__putchar('-');
		count++;
	}

	do {
		__putchar('0' + current / 1000000000);
		count++;
		current %= 1000000000;
	} while (current > 0);

	return (count);
}

/**
 * convert_number - Converts a number to a string.
 * @num: The number to convert.
 * @base: The base for conversion (e.g., 10 for decimal).
 * @flags: Argument flags (CONVERT_LOWERCASE, CONVERT_UNSIGNED).
 *
 * Return: A string representation of the number.
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}

/**
 * remove_comments - Replaces the first instance of '#' with '\0'.
 * @str: Address of the string to modify.
 *
 * Return: Always 0.
 */
void remove_comments(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '#' && (i == 0 || str[i - 1] == ' '))
		{
			str[i] = '\0';
			break;
		}
	}
}
