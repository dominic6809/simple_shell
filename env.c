#include "shell.h"
/**
 * _getenv - gets the value of an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @name: name of the environment variable
 *
 * Return: pointer to the value of the environment variable,
 *         or NULL if not found
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *value = NULL;

	while (node)
	{
		value = starts_with(node->str, name);

		if (value && *value == '=')
			return (value + 1);

		node = node->next;
	}
	return (NULL);
}
/**
 * _myenv - Prints the current environment variables.
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 *
 * Return: Always 0.
 */
int _myenv(info_t *info)
{
	char **environ = get_environ(info);
	char **env_ptr = environ;

	while (*env_ptr != NULL)
	{
		_puts(*env_ptr);
		_putchar('\n');
		env_ptr++;
	}
	return (0);
}
/**
 * _mysetenv - Sets a new environment variable or modifies an existing one.
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 *
 * Return: 0 on success , 1 on failure
 */
int _mysetenv(info_t *info)
{
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	return (1);
}
/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc < 2)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}

	for (i = 1; i < info->argc; i++)
	{
		if (_unsetenv(info, info->argv[i]))
		{
			_eputs("Failed to remove environment variable.\n");
			return (1);
		}
	}
	return (0);
}
/**
 * populate_env_list - Populates the environment variables .
 * @info: Structure containing potential arguments.
 *
 * Return: 1 on success, 0 on failure.
 */
int populate_env_list(info_t *info)
{
	char **environ;
	int i = 0;
	list_t *node = NULL;

	if (info == NULL)
		return (0);

	while (environ[i] != NULL)
	{
		if (add_node_end(&node, environ[i], 0))
		{
			while (info->env != NULL)
				delete_node_at_index(&(info->env), 0);
			return (0);
		}
		i++;
	}
	info->env_changed = 1;
	return (1);
}
