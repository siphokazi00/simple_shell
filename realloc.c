#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * _memset - Fill memory with a constant byte.
 * @s: A pointer to the memory area to fill.
 * @b: The byte value to be set.
 * @n: The number of bytes to be set to the value.
 *
 * Return: A pointer to the memory area @s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	return (memset(s, b, n));
}

/**
 * freeStringArray - Free memory allocated for an array of strings.
 * @strArray: An array of strings.
 *
 * This function iterates through each string in the @strArray and frees
 * the memory occupied by each string. It then frees the memory occupied
 * by the @strArray itself.
 */
void freeStringArray(char **strArray)
{
	char **pp = strArray;

	if (!strArray)
		return;

	while (*pp)
	{
		free(*pp);
		pp++;
	}
	free(strArray);
}

/**
 * _realloc - Reallocate memory for a dynamically allocated block.
 * @ptr: A pointer to the previously allocated memory block.
 * @old_size: The old size of the memory block.
 * @new_size: The new size of the memory block.
 *
 * Return: A pointer to the newly allocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr = malloc(new_size);

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	if (!new_ptr)
		return (NULL);

	memcpy(new_ptr, ptr, old_size < new_size ? old_size : new_size);
	free(ptr);
	return (new_ptr);
}
