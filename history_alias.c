#include "shell.h"

/**
 * _myhistory - prints the history of commands entered
 * @info: a pointer to the info_t struct.
 * Return: 1 success, to continue executing
 */
int _myhistory(info_t *info)
{
	int i, hist_count;
	list_t *hist;

	hist = info->history;
	hist_count = hist->count;

	for (i = hist_count; i > 0; i--)
	{
		printf("%d%s\n", i, hist->history[i - 1]);
	}
	return (1);
}
/**
 * _myalias - creates or outputs alias for a command.
 * @info: pointer to the info_t struct.
 * Return: 1 always upon success, to continue executing.
 */
int _myalias(info_t *info)
{
	int i, flag = 0;
	alias_t *alias;
	char *cmd;
	char ALIAS_LEN;

	alias = info->alias;
	cmd = strtok(NULL, "");

	if (cmd == NULL)
	{
		for (i = 0; i < ALIAS_LEN; i++)
		{
			if (alias[i].name != NULL)
			{
				printf("%s = '%s'\n", alias[i].name, alias[i].value);
			}
		}
	}
	else
	{
		for (i = 0; i < ALIAS_LEN; i++)
		{
			if (alias[i].name != NULL && strcmp(alias[i].name, cmd) == 0)
			{
				printf("%s = '%s'\n", alias[i].name, alias[i].value);
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			for (i = 0; i < ALIAS_LEN; i++)
			{
				if (alias[i].name == NULL)
					alias[i].name = strdup(cmd);
					alias[i].value = strdup(strtok(NULL, "\n"));
			}
		}
	}
	return (1);
}
