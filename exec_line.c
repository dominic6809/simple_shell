#include "shell.h"

/**
 * exec_line - finds builtins and commands
 *
 * @datash: parameters relevant (args)
 * Return: 1 on success.
 */
int exec_line(input_params *datash)
{
	int (*builtin)(input_params *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
