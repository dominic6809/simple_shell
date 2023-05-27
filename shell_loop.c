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
	ssize_t n = 0

	while (n != -1 && builtin_ret != -2)
	{
		clear_info(info);

		if (interactive(info))
			_puts("$ ");

		_eputchar(BUF_FLUSH);
		n = get_input(info);

		if (n ! == -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);

			if (interactive(info))
				_putchar('\n');
			free_info(info, 0);
		}
		write_history(info);
		free_info(info, 1);

		if (!interactive(info) && info->status)
			exit(info->status);
		if (builtin_ret == -2)
		{
			if (info->err_num == -1)
				exit(info->status);
			exit(info->err_num);
		}
		return (builtin_ret);
	}
/**
 * find_builtin - finds if command is a builtin
 * @info: shell info struct
 * Return: 0 if a builtin  is executed successfully 
 * -1 if not
 *  1 if builtin found is not successful
 *  2 if builtin signals exit()
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
	char *path = NULL;
	int i, t;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, t = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			t++;
	if (!t)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);

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

	if (pid == -1)
	{
		perror("Error:");
		return;
	}
	if (pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1);
		free_info(info, 1);
		if (errno == EACCES)
			exit(126);
		exit(1);
	}
	else if (pid < 0)
	{
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));

		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);

			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
