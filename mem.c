#include "shell.h"

/**
 * free_dp - frees pointer, NULLs the address
 * command: address pointer free
 * Return - 0 success
 */
void free_dp(char **command)
{
	size_t e = 0;

	if (command == NULL)
		return;

	while (command[e])
	{
		free(command[e]);
		e++;
	}

	if (command[e] == NULL)
		free(command[e]);
	free(command);
}
/**
 * free_exit - frees  memory allocated and exit
 * @command: points allocated command memory
 * Return: 0 when successful.
 */
void free_exit(char **command)
{
	size_t m = 0;

	if (command == NULL)
		return;

	while (command[m])
	{
		free(command[m]);
		m++;
	}

	if (command[m] == NULL)
		free(command[m]);
	free(command);
	exit(EXIT_FAILURE);
}
