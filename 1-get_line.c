#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/**
 * sigintHandler - Handles the SIGINT signal (Ctrl+C)
 * @signum: The signal number (ignored)
 *
 * Description: This function is called when the SIGINT signal
 * (Ctrl+C) is received. It prints a message and exits the program.
 */
void sigintHandler(int signum)
{
	(void)signum;

	exit(0);
}

#include <stdio.h>
#include <stdlib.h>

/**
 * read_buf - Read data from stdin into a buffer
 * @buffer: The buffer to read data into
 * @size: The size of the buffer
 *
 * Return: The number of bytes read, or -1 on error.
 */
ssize_t read_buf(void *buffer, size_t size)
{
	ssize_t bytesRead = fread(buffer, 1, size, stdin);

	if (buffer == NULL || size == 0)
	{
		return (-1);
	}

	if (bytesRead < 0)
	{
		perror("Error reading from stdin");
		return (-1);
	}

	return (bytesRead);
}
