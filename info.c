#include "shell.h"

/**
 * clear_info - frees all memory used by an info_t struct.
 * @info: pointer to info_t struct to clear.
 *
 */
void clear_info(info_t *info)
{
	ffree(info->av);
	ffree(info->path);
	ffree(info->env);
}

/**
 * set_info - initializes info_t struct with provided arguments
 * @info: pointer to info_t struct to initialize..
 * @av: arr of arguments to set as info->av
 */

void set_info(info_t *info, char **av)
{
	info->av = av;
	info->path = strtow(get_env_value(info, "PATH"), ":");
	info->env = (char **)environ;
}
/**
 * free_info - frees all memory used by an info_t struct
 * @info: pointer to info_t struct to free.
 * @exit_code: exit code to pass to exit()
 */
void free_info(info_t *info, int exit_code)
{
	clear_info(info);
	free(info);
	exit(exit_code);
}
