#include "main.h"

/**
 * execute - Execute a command with arguments
 * @args: Array of strings containing command and arguments
 * Return: status code of the command execution
 */
int execute(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}
	else if (_strcmp(args[0], "exit") == 0)
	{
		return (execute_exit(args));
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		return (execute_env());
	}
	else
	{
		return (execute_command(args));
	}
}

/**
 * execute_exit - Handle the "exit" command
 * @args: Array of strings containing command and arguments
 * Return: Void
 */
int execute_exit(char **args)
{
	if (args[1] != NULL)
	{
		int status = _atoi(args[1]);

		exit(status);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}

/**
 * execute_env - Handle the "env" command
 * Return: Status code of the command execution (always 1)
 */
int execute_env(void)
{
	char **env = __environ;

	while (*env != NULL)
	{
		_fputs(*env, stdout);
		_fputc('\n', stdout);
		env++;
	}
	return (1);
}

/**
 * execute_command - Execute a command with arguments
 * @args: Array of strings containing command and arguments
 * Return: Status code of the command execution
 */
int execute_command(char **args)
{
	int status;
	char *command_path = get_command_path(args[0]);

	if (command_path != NULL)
	{
		pid_t child_pid = fork();

		if (child_pid == 0)
		{
			if (execve(command_path, args, environ) == -1)
			{
				perror("execve");
				exit(-1);
			}
		}
		else if (child_pid < 0)
		{
			perror("fork");
			exit(-1);
		}
		else
		{
			wait(&status);
			free(command_path);
			if (WIFEXITED(status))
				status = WEXITSTATUS(status);
			if (!isatty(STDIN_FILENO))
				return (status);
		}
	}
	else
	{
		_fputs(program_name, stdout);
		_fputs(": 1: ", stdout);
		_fputs(args[0], stdout);
		_fputs(": not found", stdout);
		_fputc('\n', stdout);
	}

	return (0);
}
