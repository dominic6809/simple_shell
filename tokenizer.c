#include "shell.h"
/**
 * tokenizer - splits/creates  string command
 * @d: strtok delimeter
 * @buffer: string pointer input string
 * Return: full command of string
 */
char **tokenizer(char *buffer, const char *d)
{
	char *token = NULL, **commands = NULL;
	size_t bufsize = 0;
	int a = 0;

	if (buffer == NULL)
		return (NULL);

	bufsize = _strlen(buffer);
	commands = malloc((bufsize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Not able to allocate buffer");
		free(buffer);
		free_dp(commands);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, d);
	while (token != NULL)
	{
		commands[a] = malloc(_strlen(token) + 1);
		if (commands[a] == NULL)
		{
			perror("Not able to allocate buffer");
			free_dp(commands);
			return (NULL);
		}
		_strcpy(commands[a], token);
		token = strtok(NULL, d);
		a++;
	}
	commands[a] = NULL;
	return (commands);
}
