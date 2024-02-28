#include "shell.h"

/**
 * print_prompt - Prints a prompt to the stdout stream
 * Return: void
 */
void print_prompt(void)
{
	char *prompt = "$Shell ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, _strlen(prompt));
}

/**
 * prompt - Reads a line of input from the user.
 * @line: Pointer to the variable where the input line will be stored.
 * Return: 1 if a line of input was successfully read.
 *         0 if the input line is empty or end of input is reached.
 *        -1 if an error occurred while reading input.
 */
int prompt(char **line)
{
	size_t buffer_size = 0;
	ssize_t bytes_read;
	char *new_line = NULL;

	bytes_read = getline(&new_line, &buffer_size, stdin);

	if (bytes_read == -1)
	{
		free(new_line);
		return (-1);
	}
	else if (bytes_read == 0)
	{
		free(new_line);
		return (0);
	}
	else
	{
		if (new_line[bytes_read - 1] == '\n')
		{
			new_line[bytes_read - 1] = '\0';
		}
		free(*line);
		*line = new_line;
		return (1);
	}
}
