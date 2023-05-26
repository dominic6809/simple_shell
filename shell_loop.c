#include "shell.h"

/**
 * hsh - main shell function
 * @info: shell info struct
 * @av: argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int hsh(info_t *info, char **av)
{
	int builtin_ret = 0;

	while (1)
	{
		clear_info(info);

		if (interactive(info))
			_puts("$ ");

		_eputchar(BUF_FLUSH);

		if (get_input(info) == -1)
		{
			if (interactive(info))
				_putchar('\n');
			break;
		}

		set_info(info, av);
		builtin_ret = find_builtin(info);

		if (builtin_ret == -1)
			find_cmd(info);

		free_info(info, 0);
	}

	write_history(info);
	free_info(info, 1);

	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit (info->status);
		exit(info->err_num);
	}

	return (builtin_ret);
}
/**
 * find_builtin - finds if command is a builtin
 * @info: shell info struct
 * Return: 0 if a builtin, -1 if not
 */
int find_builtin(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type != NULL; i++)
	{
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);

			return (built_in_ret);
		}
	}
	return (-1);
}
/**
 * find_cmd - finds the command path
 * @info: shell info struct
 */
void find_cmd(info_t *info)
{
	char *path = find_path(info, _getenv(info, "PATH="), info->argv[0]);

	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else if ((interactive(info) || _getenv(info, "PATH=")
				|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
	{
		fork_cmd(info);
	}
	else if (*(info->arg) != '\n')
	{
		info->status = 127;
		print_error(info, "not found\n");
	}
}
/**
 * fork_cmd - forks and executes a command
 * @info: shell info struct
 */
void fork_cmd(info_t *info)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		execve(info->path, info->argv, get_environ(info));
		perror("execve");
		exit(127);
	}
	else if (pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(pid, &status, 0);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
