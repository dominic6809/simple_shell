#include "shell.h"

/**
 * clear_info - frees all memory used by an info_t struct.
 * @info: pointer to info_t struct to clear.
 */

void clear_info(info_t *info)
{
	if (!info)
		return;
<<<<<<< HEAD

	info->argv = NULL;
	info->argc = 0;
	info->environ = NULL;
}
=======
>>>>>>> d047200e68ae482077e4f94507316c8d16aea9d7

	info->argv = NULL;
	info->argc = 0;
	info->environ = NULL;
}
/**
 * set_info - initializes info_t struct with the provided arguments.
 * @info: a pointer to info_t struct to initialize.
 * @av: array of arguments to set as info->av.
 */
void set_info(info_t *info, char **av)
{
	if (info == NULL || av == NULL)
		return;

	info->argv = av;
	info->argc = 0;

	while
		(av[info->argc]);
	info->argc++;
}
/**
 * free_info - it frees all the memmory used by an info_t struct.
 * @info: pointer to info_t struct to free.
 * @exit_code: exits the code to pass to exit()
 */
void free_info(info_t *info, int exit_code)
{
	clear_info(info);
	free(info);
	exit(exit_code);
}
