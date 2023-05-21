#include "shell.h"

/**
 * get_environ - returns a copy of the environment variables as a string array
 * @info: the info_t struct containing the environment variables
 *
 * Return: a string array of environment variables, or NULL on failure
 */
char **get_environ(info_t *info)
{
	if (info->environ == NULL || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}
/**
 * _unsetenv - Remove an environment variable
 * @info: the info_t struct containing the environment variables
 * @var: the string representing the environment variable to remove
 *
 * Return: 1 if the variable is deleted, 0 otherwise
 */
int _unsetenv(info_t *info, char *var)
{
	int deleted = 0;

	if (!info->env || !var)
		return (0);

	list_t **head = &(info->env);
	list_t *node = *head;

	while (node)
	{
		char *p = starts_with(node->str, var);

		if (p && *p == '=')
		{
			break;
		}
		head = &(node->next);
		node = node->next;
	}

	info->env_changed = deleted;
	return (deleted);
}
/**
 * _setenv - Set an environment variable
 * @info: A pointer to the info_t struct
 * @name: The name of the variable to set
 * @value: The value to set the variable to
 *
 * Return: 0 on success, or -1 on failure.
 */
int _setenv(info_t *info, char *name, char *value)
{
	if (!name || !value)
		return (-1);

	char *var = malloc(strlen(name) + strlen(value) + 2);

	if (!var)
		return (-1);

	sprintf(var, "%s=%s", name, value);

	if (setenv(name, value, 1) != 0)
		return (-1);

	if (add_node_end(&(info->env), var, 0) == NULL)
		return (-1);


	return (0);
}
