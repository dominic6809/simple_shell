#include "shell.h"

/**
 * is_cmd - Check if the given command is an executable file
 * @info: pointer to the info_t struct containing the PATH variable
 * @cmd: string containing the command to check
 *
 * Return: 1 if cmd is an executable file, 0 otherwise
 */
int is_cmd(info_t *info, char *cmd)
{
	char *path = _getenv(info, "PATH");
	char *dir, *full_path;
	struct stat st;

	/* Check if cmd is an executable file in the current directory */
	if (stat(cmd, &st) == 0 && (st.st_mode & S_IXUSR))
		return (1);

	/* Check if cmd is an executable file in a directory listed in PATH */
	dir = strtok(path, ":");

	while (dir != NULL)
	{
		full_path = find_path(info, dir, cmd);

		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(full_path);

			return (1);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	return (0);
}
/**
 * dup_chars - creates a new string  from the input string.
 * @str: the string to copy from
 * @start: the starting index
 * @end: the ending index
 *
 * Return: the new string
 */
char *dup_chars(char *str, int start, int end)
{
	int i, len = end - start;
	char *new_str = malloc(len + 1);

	if (new_str == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < len; i++)
		new_str[i] = str[start + i];

	new_str[len] = '\0';

	return (new_str);
}
/**
 * find_path - finds path to the specified command and directory.
 * @info: pointer to the info_t struct containing the PATH variable
 * @dir: string containing the directory to search in
 * @cmd: string containing the command to search for
 *
 * Return: the full path to the command
 */
char *find_path(info_t *info, char *dir, char *cmd)
{
	int dir_len = strlen(dir), cmd_len = strlen(cmd);
	char *path = malloc(dir_len + cmd_len + 2);

	if (path == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if(is_cmd(info, cmd))
		return (cmd);
	if (is_cmd(info, path))
		return (path);

	snprintf(path, dir_len + cmd_len + 2, "%s/%s", dir, cmd);

	return (path);
}
