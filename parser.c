#include "shell.h"

/**
 * is_executable_file - Check if a file at the specified path is executable.
 * @info: Unused parameter (for consistency with other function prototypes).
 * @path: The path to the file to check.
 *
 * Return: 1 if the file is executable, 0 otherwise.
 */
int is_executable_file(info_t *info, char *path)
{
	struct stat st;
	(void)info;
	return (!(!path || stat(path, &st) || !(st.st_mode & S_IFREG)));
}

/**
 * copy_substring - Create a copy of a substring from a given string.
 * @str: The input string.
 * @start: The starting index of the substring.
 * @stop: The ending index of the substring.
 *
 * Return: A newly allocated string containing the copied substring,
 * or NULL if an error occurs or if the substring is empty.
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
 * find_exec_path - Find the executable path of a command in a specified path.
 * @info: Unused parameter (for consistency with other function prototypes).
 * @pathstr: The colon-separated list of directories to search for the command.
 * @cmd: The name of the command to find.
 *
 * Return: A dynamically allocated string containing the full path to the
 * executable command, or NULL if the command is not found or if an
 * error occurs.
 */
char *find_exec_path(info_t *info, const char *pathstr, const char *cmd)
{
	size_t i;
	int curr_pos = 0;

	if (!pathstr)
		return (NULL);

	for (i = 0; pathstr[i]; i++)
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
