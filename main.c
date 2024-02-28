#include "shell.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * @envp: Array of environment variables
 * Return: Always 0 successful
 */
int main(int argc, char **argv, char **envp)
{
	char *line = NULL, **args;
	int exit_status, status;
	(void)argc;
	(void)envp;
	program_name = argv[0];

	while (1)
	{
		print_prompt();
		if (prompt(&line) == -1)
			exit(0);

		args = split_line(line);
		if (args == NULL || args[0] == NULL)
			continue;

		if (_strcmp(args[0], "exit") == 0)
		{
			exit_status = (args[1] != NULL) ? _atoi(args[1]) : 0;
			free(line);
			free_args(args);
			exit(exit_status);
		}

		status = execute(args);
		free_args(args);
		free(line);
		line = NULL;

		if (status != EXIT_SUCCESS)
			break;
	}

	return (0);
}
