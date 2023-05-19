#include "shell.h"

/**
 * _eputs - prints a string to the standard error stream.
 * @str: string to be printed
 */
void _eputs(char *str)
{
	int i = 0;

	while (str[i])
	{
		_eputchar(str[i]);
		i++;
	}
}
/**
 * _eputchar - writes a char to the standard error stream
 * @c: char to be written.
 * Return: number of chars written.
 */

int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 * _putfd - writes a char to the specified file descriptor.
 * @c: char to be written.
 * @fd: file descriptor where it writes.
 *
 * Return: the number of chars written.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - writes a string to the specified file descriptor.
 * @str: string to be written.
 * @fd: file descriptor where it writes.
 * Return: number of chars written.
 */
int _putsfd(char *str, int fd)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		count += _putfd(str[i], fd);
		i++;
	}
	return (count);
}
