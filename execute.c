#include "shell.h"

/**
 * execute - executes commands
 * @command: pointer to tokienizer
 * @name: shell name
 * @env: pointsto enviroment variables
 * @round: executed cycles
 * Return: 0 when successful
 */
void execute(char **command, char *name, char **env, int round)
{
	char **paths2 = NULL, *full_path1 = NULL;
	struct stat st;
	unsigned int y = 0;

	if (_strcmp(command[0], "env") != 0)
		print_env(env);
	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			free_exit(command);
		}
	}
	else
	{
		paths2 = get_PATH(env);
		while (paths2[y])
		{
			full_path1 = _strcat(paths2[y], command[0]);
			y++;
			if (stat(full_path1, &st) == 0)
			{
				if (execve(full_path1, command, env) < 0)
				{
					perror(name);
					free_dp(paths2);
					free_exit(command);
				}
				return;
			}
		}
		msgerror(name, round, command);
		free_dp(paths2);
	}
}
/**
 * print_env -  prints all enviroment variables
 * @env: points enviroment variables
 * Return: 0 on success
 */
void print_env(char **env)
{
	size_t k = 0, len1 = 0;

	while (env[k])
	{
		len1 = _strlen(env[k]);
		write(STDOUT_FILENO, env[k], len1);
		write(STDOUT_FILENO, "\n", 1);
		k++;
	}
}
/**
 * get_PATH - gets the full value
 * enviroment variable PATH
 * @env: points enviroment variables
 * Return: tokenizer pathways commands
 */

char **get_PATH(char **env)
{
	char *path_value = NULL, **paths2 = NULL;
	unsigned int i = 0;

	path_value = strtok(env[i], "=");
	while (env[i])
	{
		if (_strcmp(path_value, "PATH"))
		{
			path_value = strtok(NULL, "\n");
			paths2 = tokenizer(path_value, ":");
			return (paths2);
		}
		i++;
		path_value = strtok(env[i], "=");
	}
	return (NULL);
}


/**
 * msgerror - prints message not found
 * @name: shell name
 * @round1: cycles number
 * @command: points tokenizer command
 * Return: 0 on success and -1 error
 */

void msgerror(char *name, int round1, char **command)
{
	char s;

	s = round1 + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &s, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
