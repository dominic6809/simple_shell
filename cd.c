#include "shell.h"
/**
 * cd_dot - Change directory to current directory
 * @datash: Pointer to input parameters
 */
void cd_dot(input_params *datash)
{
	char *current_dir = datash->args[1];

	if (current_dir == NULL)
	{
		printf("Usage: cd .\n");
		return;
	}

	if (chdir(current_dir) != 0)
		perror("cd");
}

/**
 * cd_to - Change directory to the specified directory
 * @datash: Pointer to input parameters
 */
void cd_to(input_params *datash)
{
	char *target_dir = datash->args[1];

	if (target_dir == NULL)
	{
		printf("Usage: cd [DIRECTORY]\n");
		return;
	}

	if (chdir(target_dir) != 0)
	perror("cd");
}
/**
 * cd_previous - Change directory to the previous directory
 * @datash: Pointer to input parameters
 */
void cd_previous(input_params *datash)
{
	if (chdir("..") != 0)
		perror("cd");
}

/**
 * cd_to_home - Change directory to the home directory
 * @datash: Pointer to input parameters
 */
void cd_to_home(input_params *datash)
{
	char *home_dir = _getenv("HOME", datash->_environ);

	if (home_dir == NULL)
	{
		printf("cd: No home directory found\n");
		return;
	}

	if (chdir(home_dir) != 0)
		perror("cd");
}
