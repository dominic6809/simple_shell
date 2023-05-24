#include "shell.h"

/**
 * _myexit - it exits the shell
 * @info: pointer to info_t struct.
 * Return: 0 always on success.
 */
int _myexit(info_t *info)
{
	int exit_status = 0;

	/* check for arguments */
	if (info->arg[1])
	{
		/* convert argument to integer */
		exit_status = _atoi(info->arg[1]);
	}
	/* frees mem */
	free_info(info, 1);
	/* exits shell */
	exit(exit_status);
}
/**
 * _mycd - changes current working directory.
 * @info: pointer to info_t struct.
 * Return: always 0 on success.
 */
int _mycd(info_t *info)
{
	char *dir;

	/* if no argument is passed, change to home directory */
	if (!info->arg[1])
	{
		dir = _getenv(info, "HOME");
		/* if HOME var is not set, print error */
		if (!dir)
		{
			_puts("cd: HOME not set\n");
			return (1);
		}
	}
	else
	{
		dir = info->arg[1];
	}
	/* change dir */
	if (chdir(dir) == -1)
	{
		/* if dir does not exist, print error */
		perror("cd");
	}
	return (0);
}
/**
 * _myhelp - display help information for built-in commands.
 * @info: pointer to info_t struct.
 * Return: 0 always on success.
 */
int _myhelp(info_t *info)
{
	int i;
	char *commands[] = {
		"cd", "exit", "help", NULL
	};
	char *descriptions[] = {
		"change directory",
		"exit the shell",
		"display help information for built-in commands"
	};
	/* print help information for each command */
	for (i = 0; commands[i]; i++)
	{
		dprintf("%s - %s\n", commands[i], descriptions[i]);
	}
	return (0);
}
