#include "shell.h"
#include <string.h>

/**
 * command_parser - Parses a string into tokens using delimiter.
 * @line: The string to parse.
 * @delimiter: The delimiter used to tokenize the string.
 * Return: A double pointer to an array of tokens on success,
 *         NULL on failure or if @line or @delimiter is NULL.
 */
char **command_parser(char *line, const char *delimiter)
{
	char **tokens = NULL;
	char *token = NULL;
	size_t i = 0;

	if (line == NULL || delimiter == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	line[strcspn(line, "\n")] = '\0';
	line[strcspn(line, "#")] = '\0';

	token = custom_strtok(line, delimiter);
	while (token != NULL)
	{
		tokens = realloc(tokens, (i + 2) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	tokens[i] = token;
	i++;
	token = custom_strtok(NULL, delimiter);
	}
	tokens[i] = NULL;

	return (tokens);
}
