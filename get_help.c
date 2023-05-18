#include <shell.h>

/**
 * get_help - Display help information based on the input command
 * @datash: Pointer to input parameters
 *
 * Return: 0 on success, -1 if help information not available
 */
int get_help(input_params *datash)
{
	char *command = datash->args[0];

	if (strcmp(command, "env") == 0)
	{
		printf("env: env\n");
		printf("    Print the environment variables.\n");
	}
	else if (strcmp(command, "setenv") == 0)
	{
		printf("setenv: setenv [VARIABLE] [VALUE]\n");
		printf("    Set the value of an environment variable.\n");
	}
	else if (strcmp(command, "unsetenv") == 0)
	{
		printf("unsetenv: unsetenv [VARIABLE]\n");
		printf("    Remove an environment variable.\n");
	}
	else if (strcmp(command, "exit") == 0)
	{
		printf("exit: exit\n");
		printf("    Exit the shell.\n");
	}
	else if (strcmp(command, "alias") == 0)
	{
		printf("alias: alias [NAME[='VALUE'] ...]\n");
		printf("    Define or display aliases.\n");
	}
	else if (strcmp(command, "cd") == 0)
	{
		printf("cd: cd [DIRECTORY]\n");
		printf("    Change the current working directory.\n");
	}
	else
	{
		printf("Help information not available for command: %s\n", command);
		return (-1);
	}
	return (0);
}
