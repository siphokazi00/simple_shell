#include "shell.h"

/**
 * get_environ - Returns the string array copy of our environ.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: String array copy of environ.
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}

/**
 * _unsetenv - Remove an environment variable.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @var: The string env var property.
 * Return: 1 on delete, 0 otherwise.
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
		return (info->env_changed);
}

/**
 * _setenv - Set or update an environment variable.
 * @info: The parameter struct.
 * @var: The variable name.
 * @value: The variable value.
 * Return: 0 on success, 1 on failure.
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	int found = find_env_node(info, var, value);

	if (!var || !value)
		return (0);
	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	if (found)
	{
		free(buf);
		return (0);
	}
	add_env_node(info, var, value);
	free(buf);
	info->env_changed = 1;
	return (0);
}
