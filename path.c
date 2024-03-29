#include "main.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 200

/**
 * get_command_path - Get the full path of a command using the PATH variable
 * @command: Command to find
 * Return: Full path of the command if found, NULL otherwise
 */

char *get_command_path(char *command)
{
	char *path, *dir, *full_path, *token;

	if (_strchr(command, '/') != NULL)
	{
		return (_strdup(command));
	}
	path = _getenv("PATH");

	if (path == NULL)
	{
		write(STDERR_FILENO, "Error retrieving PATH variable\n", 31);
		return (NULL);
	}
	token = strtok(path, ":");

	while (token != NULL)
	{
		dir = _strdup(token);
		full_path = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_path == NULL)
		{
			write(STDERR_FILENO, "Allocation error\n", 17);
			free(dir);
			return (NULL);
		}
		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(dir);
			return (full_path);
		}
		free(full_path);
		free(dir);
		token = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * build_command_path - Build the full path of a command
 * @directory: Directory to prepend to the command
 * @command: Command to append to the directory
 * Return: Full path of the command
 */

char *build_command_path(char *directory, char *command)
{
	size_t directory_len = _strlen(directory);
	size_t command_len = _strlen(command);
	size_t path_len = directory_len + command_len + 2;
	char *path = malloc(path_len);

	if (path == NULL)
	{
		write(STDERR_FILENO, "Allocation error\n", 17);
		exit(EXIT_FAILURE);
	}
	_strncpy(path, directory, directory_len);

	path[directory_len] = '/';
	_strncpy(path + directory_len + 1, command, command_len);
	path[path_len - 1] = '\0';
	return (path);
}
