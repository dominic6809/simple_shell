#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * copy_info - Copy name and value into a new string
 * @name: Name of the environment variable
 * @value: Value of the environment variable
 *
 * Return: Pointer to the new string, or NULL on failure
 */
char *copy_info(char *name, char *value)
{
	int len_name, len_value, len_total;
	char *new_info;

	if (name == NULL || value == NULL)
		return (NULL);

	len_name = strlen(name);
	len_value = strlen(value);
	len_total = len_name + len_value + 2; /* +2 for '=' and '\0' */

	new_info = malloc(sizeof(char) * len_total);
	if (new_info == NULL)
		return (NULL);

	snprintf(new_info, len_total, "%s=%s", name, value);

	return (new_info);
}
/**
 * set_env - Set the value of an environment variable
 * @name: Name of the environment variable
 * @value: Value of the environment variable
 * @datash: Pointer to input parameters
 */
void set_env(char *name, char *value, input_params *datash)
{
	int i, len_name, cmp;
	char **env = datash->_environ;

	len_name = strlen(name);

	for (i = 0; env[i] != NULL; i++)
	{
		cmp = strncmp(name, env[i], len_name);
		if (cmp == 0 && env[i][len_name] == '=')
		{
			free(env[i]);
			env[i] = copy_info(name, value);
			return;
		}
	}
	/* If the environment variable does not exist, add it */
	env[i] = copy_info(name, value);
	env[i + 1] = NULL;
}
/**
 * _setenv - Set the value of an environment variable
 * @datash: Pointer to input parameters
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(input_params *datash)
{
	char *name, *value;

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		printf("Usage: setenv [VARIABLE] [VALUE]\n");
		return (-1);
	}

	name = datash->args[1];
	value = datash->args[2];

	set_env(name, value, datash);

	return (0);
}

/**
 * _unsetenv - Unset an environment variable
 * @datash: Pointer to input parameters
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(input_params *datash)
{
	char *variable = datash->args[1];

	if (variable == NULL)
	{
		printf("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	if (unsetenv(variable) != 0)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}
