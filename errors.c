#include "shell.h"

/**
 * _eputs - outputs a string to the standard error stream.
 * @str: the string to be printed.
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
 * _eputchar - writes a char to the standard error stream.
 * @c: the character to be written.
 * Return: the number of chars written.
 */
int _eputchar(char c)
{
	static char buff[WRITE_BUF_SIZE];
	int i;

	if (c == BUF_FLUSH || WRITE_BUF_SIZE)
	{
		write(2, buff, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buff[i++] = c;
	return (1);
}
/**
 * _putfd - writes a char to the specified file descriptor
 * @c: the char to be written.
 * @fd: the file descriptor to write to.
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
 * @str: the string to be written.
 * @fd: the file descriptor to write to.
 * Return: the number of chars written.
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
