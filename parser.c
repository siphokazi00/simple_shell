#include "shell.h"

/**
 * is_executable_file - Determines if a file is executable
 * @info: the info struct
 * @path: file path
 *
 * Return: 1 if true, 0 otherwise.
 */
int is_executable_file(info_t *info, char *path)
{
	struct stat st;
	(void)info;
	return (!(!path || stat(path, &st) || !(st.st_mode & S_IFREG)));
}

/**
 * *copy_substring - Duplicates characters
 * @substr: substring
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to the new buffer
 */
char *copy_substring(const char *str, int start, int stop)
{
	char *substr = NULL;
	int len = stop - start;

	if (len <= 0)
		return (NULL);

	substr = malloc(len + 1);
	if (substr)
	{
		strncpy(substr, str + start, len);
		substr[len] = '\0';
	}
	return (substr);
}

/**
 * *find_exec_path -
 */
char *find_exec_path(info_t *info, const char *pathstr, const char *cmd)
{
	if (!pathstr)
		return (NULL);

	size_t cmdLen = _strlen(cmd);
	int curr_pos = 0;

	for (size_t i = 0; pathstr[i]; i++)
	{
		if (pathstr[i] == ':')
		{
			char *path = copy_substring(pathstr, curr_pos, i);
			if (path)
			{
				if (path[0] != '\0')
				{
					_strcat(path, "/");
				}
				_strcat(path, cmd);
				if (is_executable_file(info, path))
				{
					return (path);
				}
			}
			free(path);
			curr_pos = i + 1;
		}
	}

	return (NULL);
}
