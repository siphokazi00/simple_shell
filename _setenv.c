#include "shell.h"

/**
 * find_env_node - Find an environment variable node.
 * @info: The parameter struct.
 * @var: The variable name to find.
 * @value: The variable value.
 *
 * Return: 1 if found and updated, 0 if not found.
 */
int find_env_node(info_t *info, char *var, char *value)
{
	list_t *node;
	char *p;

	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = _strdup(value);
			info->env_changed = 1;
			return (1);
		}
		node = node->next;
	}
	return (0);
}

/**
 * add_env_node - Add a new environment variable node.
 * @info: The parameter struct.
 * @var: The variable name to add.
 * @value: The variable value.
 */
void add_env_node(info_t *info, char *var, char *value)
{
	char *buf = NULL;

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return;

	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	add_node_end(&(info->env), buf, 0);
}
