#include "shell.h"

/**
 * is_chain - Checks if  command line contains chaining operators.
 *
 * @info: Pointer to the info_t struct.
 * @cmd_line: Command line input from the user.
 * @i: Pointer to the current index in the command line.
 *
 * Return: 1 if chaining operator is found, 0 otherwise.
 */
int is_chain(info_t *info, char *cmd_line, size_t *i)
{
	char *operators[] = {"&&", "||", ";"};
	size_t op_count = sizeof(operators) / sizeof(operators[0]);
	size_t j = 0;

	for (j = 0; j < op_count; j++)
	{
		if (starts_with(cmd_line + *i, operators[j]))
		{
			check_chain(info, cmd_line, i, j, _strlen(operators[j]));
			return (1);
		}
	}
	return (0);
}

/**
 * check_chain - Processes a chaining operator in a command line input.
 * @buf: char buffer
 * @m: current address position in buf
 * @info: Pointer to the info_t struct.
 * @i: Pointer to the current index in the command line.
 * @len: buf length
 */
void check_chain(info_t *info, char *buf, size_t *m, size_t i, size_t len)
{
	size_t n = *m;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			n = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			n = len;
		}
	}

	*m = n;

}

/**
 * replace_alias - Replaces alias with their corresponding commands.
 * @info: Pointer to the info_t struct.
 *
 * Return: 1 if a replacement is made, 0 otherwise.
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *m;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		m = _strdup(m + 1);
		if (!m)
			return (0);
		m = _strchr(node->str, '=');
		if (!m)
			return (0);
		info->argv[0] = m;
	}
	return (1);
}
/**
 * replace_vars - replaces variables in a string with their values
 * @info: a pointer to the info_t struct
 * Return: 1 on success, 0 on failure
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - Replaces the value of a string pointer with a new string
 *
 * @old: Pointer to the old string
 * @new: New string to replace with
 *
 * Return: 1 on success, 0 on failure
 */
int replace_string(char **old, char *new)
{
	if (old == NULL || new == NULL)
		return (0);

	free(*old);
	*old = _strdup(new);

	if (*old == NULL)
		return (0);

	return (1);
}
