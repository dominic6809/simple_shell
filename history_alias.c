#include "shell.h"

/**
 * _myhistory - prints the history of commands entered
 * @info: a pointer to the info_t struct.
 * Return: 1 success, to continue executing.
 */
int _myhistory(info_t *info)
{
	int count = 1;
	list_t *node = info->history;

	while
		(node)
		{
			printf("%d\n", count);
			node = node->next;
			count++;
		}
	return (0);
}
/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	int ret;
	char *p, *alias, *value;

	p = _strchr(str, '=');

	if (!p)
		return (1);

	alias = str;
	value = p + 1;
	p = '\0';

	if (ret == 1)
		return (1);

	return (0);
}
/**
 * _myalias - create or print an alias for a command
 * @info: a pointer to the info_t struct.
 * Return: 0 always
 */
int _myalias(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		print_list(info->alias);

		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		char *m = _strchr(info->argv[i], '=');

		if (m)
			set_alias(info, info->argv[i]);
	}
	return (0);
}
/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *m = NULL, *t = NULL;

	if (node)
	{
		m = _strchr(node->str, '=');

		for (t = node->str; t <= m; t++)
			_putchar(*t);
		_putchar('\'');
		_puts(m + 1);
		_puts("'\n");

		return (0);
	}
	return (1);
}
