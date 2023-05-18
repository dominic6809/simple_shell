#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _getenv - Get the value of an environment variable
 * @name: Name of the environment variable
 * @_environ: Pointer to the array of environment variables
 *
 * Return: Value of the environment variable, or NULL if not found
 */
char *_getenv(const char *name, char **_environ)
{
	int i, len, cmp;

	if (name == NULL || _environ == NULL)
		return (NULL);

	len = strlen(name);

	for (i = 0; _environ[i] != NULL; i++)
	{
		cmp = strncmp(name, _environ[i], len);
		if (cmp == 0 && _environ[i][len] == '=')
			return (&(_environ[i][len + 1]));
	}
	return (NULL);
}
/**
 * _env - Print the environment variables
 * @datash: Pointer to input parameters
 *
 * Return: Always returns 0
 */
int _env(input_params *datash)
{
	int i;
	char **env = datash->_environ;

	for (i = 0; env[i] != NULL; i++)
		printf("%s\n", env[i]);

	return (0);
}
