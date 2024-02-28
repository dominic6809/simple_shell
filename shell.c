#include "shell.h"

/**
 * main - function runs shell
 * @ac: number input arguments
 * @av: pointer array inputed arguments
 * @env: pointer array of enviroment variables
 * Return: Always 0 success
 */

int main(int ac, char **av, char **env)
{
	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t chars_read = 0;
	int why = 0;
	(void)ac;

	while (1)
	{
		why++;
		prompt();
		signal(SIGINT, handle);
		chars_read = getline(&buffer, &buf_size, stdin);
		if (chars_read == EOF)
			_EOF(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			command = tokenizer(buffer, " \0");
			free(buffer);
			if (_strcmp(command[0], "exit") != 0)
				shell_exit(command);
			else if (_strcmp(command[0], "cd") != 0)
				cd_dir(command[1]);
			else
				bety(command, av[0], env, why);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (chars_read == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
/**
 * prompt - prints function prompt
 * Return: Always 0
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 13);
}
/**
 * handle - handle Ctr + C signal
 * @signals: signal handler
 * Return: Always 0
 */
void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\n$ ", 13);
}
/**
 * _EOF - chaecks buffer EOF (End of File)
 * @buffer: points input string
 * Return: Always 0
 */
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}
/**
 * shell_exit - exits the shelli
 * @command: points tokenizer command
 * Return: Always 0
 */

void shell_exit(char **command)
{
	int condition = 0;

	if (command[1] == NULL)
	{
		free_dp(command);
		exit(EXIT_SUCCESS);
	}

	condition = _atoi(command[1]);
	free_dp(command);
	exit(condition);
}
