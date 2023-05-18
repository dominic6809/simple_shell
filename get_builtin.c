#include <stdio.h>
#include <string.h>

/**
 * get_builtin - Get a pointer to the appropriate built-in function
 * @cmd: Command name
 * Return: Pointer to the corresponding built-in function, or NULL if not found
 */
int (*get_builtin(char *cmd))(input_params *)
{
	if (strcmp(cmd, "cd") == 0)
		return (&cd_shell);
	else if (strcmp(cmd, "env") == 0)
		return (&_env);
	else if (strcmp(cmd, "setenv") == 0)
		return (&_setenv);
	else if (strcmp(cmd, "unsetenv") == 0)
		return (&_unsetenv);
	else if (strcmp(cmd, "help") == 0)
		return (&get_help);

	return (NULL);
}
