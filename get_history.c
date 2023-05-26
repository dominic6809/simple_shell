#include "shell.h"

/**
 * get_history_file - Returns the path to the history file.
 * @info: The parameter struct.
 *
 * Return: The path to the history file, or NULL on failure.
 */
char *get_history_file(info_t *info)
{
	char *dir;
	char *file_path = NULL;

	dir = _getenv(info, "HOME=");

	if (dir == NULL)
		return (NULL);

	file_path = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));

	if (file_path == NULL)
	{
		return (NULL);
	}
	_strcpy(file_path, dir);

	if (file_path[_strlen(dir) - 1] != '/')
	{
		file_path[_strlen(dir)] = '/';
		file_path[_strlen(dir) + 1] = '\0';
	}
	_strcat(file_path, HIST_FILE);
	free(dir);
	_strcpy(file_path, dir);

	return (file_path);
}
/**
 * renumber_history - Renumber the history list
 * @info: Pointer to the info_t struct
 *
 * Return: 1 on success, 0 on failure
 */
int renumber_history(info_t *info)
{
	list_t *current = info->history;
	int i = 0;

	while (current)
	{
		current->num = i++;
		current = current->next;
	}
	return (1);
}
/**
 * build_history_list - Builds the history list from the input buffer
 * @info: Pointer to the info_t struct
 * @buf: Input buffer containing the history entries
 * @linecount: The starting index of the history entries
 *
 * Return: The number of history entries added
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	char *p = buf, *end;
	char *entry;
	int count = 0;

	if (!p || !*p)
		return (0);
	while
		((end = strchr(p, '\n')))
		{
			*end = '\0';
			entry = strdup(p);

			if (!entry)
				return (count);
			if (!add_node_end(&(info->history), entry, linecount + count))
				return (count);

			p = end + 1;
			count++;
		}
	return (count);
}
/**
 * read_history - Reads the history file and stores in info struct
 * @info: Pointer to the info_t struct
 *
* Return: 1 on success, 0 on failure
 */
int read_history(info_t *info)
{
	char *history_file = get_history_file(info);
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int linecount = 0;
	list_t *node = NULL;

	if (!history_file)
		return (0);

	fp = fopen(history_file, "r");
	if (!fp)
	{
		free(history_file);
		return (0);
	}
	while
		((read = getline(&line, &len, fp)) != -1)
		{
			if (read > 0 && line[read - 1] == '\n')
				line[read - 1] = '\0';

			node = info->history;
			add_node_end(&node, line, linecount);

			if (!add_node_end(&(info->history), line, linecount))
			{
				free(history_file);
				fclose(fp);

				return (0);
			}
			linecount++;
		}
	free(line);
	fclose(fp);
	free(history_file);

	return (1);
}
/**
 * write_history - Writes the command history to a file
 * @info: Pointer to the info_t struct
 *
 * Return: 1 on success, -1 on failure
 */
int write_history(info_t *info)
{
	char *history_file  = get_history_file(info);
	int fd;
	list_t *node = NULL;

	if (!history_file)
		return (-1);

	fd = open(history_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)
	{
		free(history_file);
		return (-1);
	}
	for (node = info->history; node; node = node->next)
	{
		if (write(fd, node->str, _strlen(node->str)) == -1 ||
				write(fd, "\n", 1) == -1)
		{
			close(fd);
			free(history_file);

			return (-1);
		}
	}
	close(fd);
	free(history_file);

	return (1);
}
