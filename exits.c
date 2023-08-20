#include "shell.h"

/**
 * _strncpy - Copies a string up to 'n' characters.
 * @dest: The destination string to copy to.
 * @src: The source string.
 * @n: The maximum number of characters to copy.
 *
 * Return: A pointer to the destination string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *destination = dest;

	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return (destination);
}

/**
 * _strncat - Concatenates 'n' characters from 'src' to 'dest'.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of characters to concatenate.
 *
 * Return: A pointer to the destination string.
 */
char *_strncat(char *dest, char *src, int n)
{
	char *destination = dest;
	char *dest_end = dest;

	while (*dest_end)
		dest_end++;

	while (*src != '\0' && n > 0)
	{
		*dest_end = *src;
		dest_end++;
		src++;
		n--;
	}

	*dest_end = '\0';
	return (destination);
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be searched.
 * @c: The character to look for.
 *
 * Return: A pointer to the first occurrence of the character in 's'.
 *         NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	for (; *s != '\0'; s++)
	{
		if (*s == c)
			return (s);
	}
	return (NULL);
}
