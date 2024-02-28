#include "main.h"

/**
 * print_prompt - Prints a prompt to the stdout stream
 * Return: void after successful execution
 */

void print_prompt(void)
{
	char *prompt = "($) ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, _strlen(prompt));
}
/**
 * prompt - Reads a line of input from the user.
 * @line: Pointer to the variable where the input line will be stored.
 * Return: 1 if a line of input was successfully read.
 *	0 if the input line is empty or end of input is reached.
 *	-1 if an error occurred while reading input.
 */
int prompt(char **line)
{
	size_t bufferSize = 0;
	ssize_t bytesRead;
	char *newLine = NULL;

	bytesRead = getline(&newLine, &bufferSize, stdin);

	if (bytesRead == -1)
	{
		free(newLine);
		return (-1);
	}
	else if (bytesRead == 0)
	{
		free(newLine);
		return (0);
	}
	else
	{
		if (newLine[bytesRead - 1] == '\n')
		{
			newLine[bytesRead - 1] = '\0';
		}
		free(*line);
		*line = newLine;
		return (1);
	}
}
