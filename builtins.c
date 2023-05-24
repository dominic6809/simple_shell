#include "shell.h"
/**
 * _myexit - exit the shell.
 * @info: pointer to info struct.
 *
 * Return: 0 always when successful
 */
int _myexit(info_t *info)
{
	int exit_status = 0;

	/* check for arguments */
	if (info->argv[1])
	{
		/* converts args to an integer */
		exit_status = _erratoi(info->argv[1]);
	}
	/* free mem */
	free_info(info, 1);

	/* exit shell */
	exit(exit_status);
}
/**
 * _mycd - change current working directory.
 * @info: pointer to info struct.
 * Return: 0 always on success
 */
int _mycd(info_t *info)
{
	char *dir;

	/* if no argument is passed, change to home directory */
	if (!info->arg[1])
	{
		dir = _getenv(info, "HOME");

		/* if HOME var is not set, output error */
		if (!dir)
		{
			_puts("cd: HOME not set \n");
			return (1);
		}
	}
	else
	{
		dir = info->argv[1];
	}
	/* change directory */
	if (chdir(dir) == -1)
	{
		/* if dir does not exist, print error */
		perror("cd");
	}
	return (0);
}

/**
 * _myhelp - display help information for built-in commands.
 * @info: pointer to info struct.
 * Return: 0 when successful
 */
int _myhelp(info_t *info)
{
	(void)info;
	char **arg_array = info->argv;

	-puts("help info:\n");
	if (arg_array)
		-puts(*arg_array);

	return (0);
}
