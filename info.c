#include "shell.h"

/**
 * clear_info - it frees all the mem used by an info_t struct.
 * @info: a pointer to info_t struct to clear
 */
void clear_info(info_t *info)
{
	if (!info)
		return;

	info->argv = NULL;
	info->argc = 0;
	info->environ = NULL;
}
/**
 * set_info - it initializes info_t struct with provided arguments.
 * @info: pointer to info_t struct to initialize.
 * @av: array of arguments to set as info->av
 */

void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];

	if (info->arg)
		info->argv = strtow(info->arg, " \t");

	if (!info->argv)
	{
		info->argv = malloc(sizeof(char *) * 2);
		if (info->argv)
		{
			info->argv[0] = _strdup(info->arg);
			info->argv[1] = NULL;
		}
		for (i = 0; info->argv && info->argv[i]; i++)

			info->argc = 0;

		replace_alias(info);
		replace_vars(info);
}
/**
 * free_info - it frees all memory used by info_t struct
 * @info: pointer to info_t struct to free.
 *
 * @all: freeing all fields
 */
void free_info(info_t *info, int all)
{
	info->argv = NULL;
	ffree(info->argv);
	info->path = NULL;

	if (all)
		ffree(all)
}
