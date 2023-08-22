#include "shell.h"

/**
 * input_buf - Reads input into a buffer for chained commands.
 * @info: Parameter struct.
 * @buf: Address of the buffer.
 * @len: Address of the buffer length variable.
 *
 * Return: Number of bytes read.
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}

			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			*len = r;
			info->cmd_buf = buf;
		}
	}
	return (r);
}

/**
 * get_input - Gets a line of input without the newline character.
 * @info: Parameter struct.
 *
 * Return: Number of bytes read.
 */
ssize_t get_input(info_t *info)
{
	char *buf = NULL;
	size_t i = 0, j = 0, len = 0;
	ssize_t r = 0;
	char **buf_p = &(info->arg);
	char *p = buf + i;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1)
		return (-1);

	if (len)
	{
		j = i;

		check_chain(info, buf, &j, i, len);
		while (j < len)
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}
		*buf_p = p;
		return (_strlen(p));
	}
	*buf_p = buf;
	return (r);
}

/**
 * _getline - Gets the next line of input from STDIN.
 * @info: Parameter struct.
 * @ptr: Address of a pointer to the buffer (preallocated or NULL).
 * @length: Size of the preallocated buffer if not NULL.
 *
 * Return: Number of characters read.
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	char buf[READ_BUF_SIZE] = {'\0'};
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;
	size_t i = 0, len = 0;
	size_t k;

	p = *ptr;
	if (p && length)
		s = *length;

	r = read_buf(info, &p, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;

	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}
