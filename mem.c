#include "main.h"
/**
 * parse_command - parse the command string into tokens
 * @command: command string to parse
 * Return: array of pointers to the token
 */

char **parse_command(char *command)
{
	char **tokens = malloc(sizeof(char *) * MAX_TOKENS);
	char *token;
	int i = 0;

	if (!tokens)
	{
		perror("Failed to allocate memory");
		return (NULL);
	}

	token = strtok(command, DELIMITER);

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, DELIMITER);
	}

	tokens[i] = NULL;
	return (tokens);
}

/**
 * free_tokens - frees the memory allocated for the tokens array
 * @tokens: array of pointers to the tokens
 *
 */

void free_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens[i]);
}
