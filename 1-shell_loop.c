#include "shell.h"

/**
 * find_path - Find the full path to a command in a list of directories
 * @info: Structure containing potential arguments.
 * @pathstr: The PATH string to search.
 * @cmd: The command to search for.
 *
 * Return: The full path to the command if found, NULL otherwise.
 */
char *find_path(info_t *info, const char *pathstr, const char *cmd)
{
	char **paths = strtow((char *)pathstr, ":");
	char *result = NULL;
	size_t i;

	if (paths == NULL)
		return (NULL);

	for (i = 0; paths[i]; i++)
	{
		char *h = _strcat(_strcat(_strdup(paths[i]), "/"), cmd);

		if (access(h, F_OK | X_OK) == 0)
		{
			result = h;
			break;
		}
		free(h);
	}

	(void)info;

	freeStringArray(paths);
	return (result);
}

/**
 * print_cmd - Print information about the executed command
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @cmd: The name of the command
 *
 * Return: Always 0
 */
int print_cmd(info_t *info, char *cmd)
{
	(void)info;
	(void)cmd;

		return (0);
}
