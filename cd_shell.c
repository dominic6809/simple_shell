#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
/**
 * cd_shell - Change directory
 * @datash: Pointer to input parameters
 * Return: 0 on success, -1 on failure
 */
int cd_shell(input_params *datash)
{
	char *dir = datash->args[1];
	int result;

	if (dir == NULL)
	{
		fprintf(stderr, "cd: missing directory\n");
		return (-1);
	}
	result = chdir(dir);
	if (result != 0)
	{
		perror("cd");
		return (-1);
	}

	return (0);
}
