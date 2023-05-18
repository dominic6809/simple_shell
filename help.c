#include <stdio.h>

/**
 * aux_help_env - Display help information for the "env" command
 */
void aux_help_env(void)
{
	printf("env: env\n");
	printf("    Print the environment variables.\n");
}

/**
 * aux_help_setenv - Display help information for the "setenv" command
 */
void aux_help_setenv(void)
{
	printf("setenv: setenv [VARIABLE] [VALUE]\n");
	printf("Set the value of an environment variable.\n");
}
/**
 * aux_help_unsetenv - Display help information for the "unsetenv" command
 */
void aux_help_unsetenv(void)
{
	printf("unsetenv: unsetenv [VARIABLE]\n");
	printf("Remove an environment variable.\n");
}

/**
 * aux_help_general - Display general help information
 */
void aux_help_general(void)
{
	printf("Shell Help\n");
	printf("Available commands:\n");
	printf("env\n");
	printf("setenv\n");
	printf("unsetenv\n");
	printf("exit\n");
}

/**
 * aux_help_exit - Display help information for the "exit" command
 */
void aux_help_exit(void)
{
	printf("exit: exit\n");
	printf("Exit the shell.\n");
}
