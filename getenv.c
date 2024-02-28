#include "main.h"

/**
 * builtin_exit - Exit the shell
 * Return: 0 to exit the shell
 */
int builtin_exit(void)
	{
		return (0);
	}

/**
 * builtin_env - Print the environment variables
 * @env: Environment variables
 * Return: Always returns 1 when successful
 */

int builtin_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
	write(STDOUT_FILENO, env[i], _strlen(env[i]));
	write(STDOUT_FILENO, "\n", 1);
	}

	return (1);
}
