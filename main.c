#include "shell.h"

/**
 * free_parameters - frees parameters structure
 *
 * @datash: parameters structure
 * Return: no return
 */
void free_parameters(input_params *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_parameters - Initialize parameters structure
 *
 * @datash: parameters structure
 * @argv: argument vector
 * Return: no return
 */
void set_parameters(input_params *datash, char **argv)
{
	unsigned int i;

	datash->argv = argv;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	input_params datash;
	(void) argc;

	signal(SIGINT, get_sigint);
	set_parameters(&datash, argv);
	shell_loop(&datash);
	free_parameters(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
