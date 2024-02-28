#include "shell.h"

#define MAX_ARGS 64
#define MAX_ARG_LENGTH 16

/**
 * split_line - Split a line into separate arguments
 * @line: The line to be split
 * Return: Array of strings containing the arguments
 */
char **split_line(char *line)
{
	char *DELIM = " \t\r\n\a";
	char *arg;
	int i = 0;
	int j;
	char **args = malloc((MAX_ARGS + 1) * sizeof(char *));

	if (args == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	for (arg = strtok(line, DELIM);
	arg != NULL && i < MAX_ARGS;
	arg = strtok(NULL, DELIM))
	{
		args[i] = malloc((MAX_ARG_LENGTH + 1) * sizeof(char));
		if (args[i] == NULL)
		{
			perror("malloc failed");
			for (j = 0; j < i; j++)
			{
				free(args[j]);
			}
			free(args);
			return (NULL);
		}
		strncpy(args[i], arg, MAX_ARG_LENGTH);
		args[i][MAX_ARG_LENGTH] = '\0';
		i++;
	}
	args[i] = NULL;
	return (args);
}
/**
 * handle_semicolon - Handles the semicolon operator in a line of code.
 * @line: The input line to process.
 * Return: The result of processing the semicolon.
 */
int handle_semicolon(char *line)
{
	char **commands = split_line(line);
	int i;

	for (i = 0; commands[i] != NULL; i++)
	{
	int status = execute((char **)commands[i]);

	if (status != 0)
	{
	return (status);
	}
	}

	free_args(commands);

	return (0);
}
