#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * *_memset
 */
#include <string.h>

char *_memset(char *s, char b, unsigned int n)
{
	return (memset(s, b, n));
}
/**
 * free_string_array - 
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
 * _realloc -
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
