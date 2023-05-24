#include "shell.h"

/**
 * get_input - reads input from STDIN and stores it in info_t struct
 * @info: pointer to info_t struct.
 *
 * Return: number of chars read or (-1) incase of an error.
 */
ssize_t get_input(info_t *info)
{
	ssize_t chars_read;

	if (info == NULL)
		return (-1);

	/* read input from STDIN using getline */
	chars_read = _getline(STDIN_FILENO, info->buffer, BUF_size);
	if (chars_read == -1)
		perror("_getline");

	return (chars_read);
}
/**
 * _getline - reads a line from STDIN.
 * @info: pointer to info_t struct.
 * @buffer: pointer to buffer to store line
 * @buf_size: pointer to size of buffer.
 *
 * Return: number of characters read or -1 incase error
 */
int _getline(info_t *info, char **buffer, size_t *buf_size)
{
	int chars_read;

	/* handle SIGINT signal */
	signal(SIGINT, sigintHandler);

	/* read input from STDIN using getline */
	chars_read = getline(buffer, buf_size, stdin);
	if (chars_read == -1)
	{
		/* handle EOF */
		if (feof(stdin))
		{
			_puts("\n");
			ffree(buffer);
			return (-1);
		}
		perror("getline");
		ffree(buffer);
		return (-1);
	}
	/* remove trailing newline char */
	if ((*buffer)[chars_read - 1] == '\n')
		(*buffer)[chars_read - 1] = '\0';
	if (_strlen(*buffer) == 0)
	{
		ffree(buffer);
		return (-1);
	}
	return (chars_read);
}
/**
 * sigintHandler - handles SIGINT signal.
 * @sig_num: signal number
 */
void sigintHandler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n");
		_puts(PROMPT);
		fflush(stdout);
	}
}
