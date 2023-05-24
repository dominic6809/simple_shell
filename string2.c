#include "shell.h"

/**
 * _strcpy - Copies the string to the buffer pointed to by dest.
 * @src: The source string.
 * @dest: The destination string.
 * Return: A pointer to the org destination string.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;
	char *orig_dest = dest;

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (orig_dest);
}

/**
 * _strdup - Duplicates a string.
 * @str: string to duplicate
 *
 * Return: a pointer to the duplicate string.
 */
char *_strdup(const char *str)
{
	char *duplicate;
	int length, i;

	if (str == NULL)
		return (NULL);

	length = 0;
	while (str[length] != '\0')
		length++;

	duplicate = malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	return (duplicate);
}

/**
 * _puts - outputs the null-terminated string pointed to by str to stdout.
 * @str: string to be printed
 *
 * Return: nothing.
 */
void _puts(char *str)
{
	int i = 0;

	while (*str)
	{
		_putchar(str[i++]);
	}
	_putchar('\n');
}

/**
 * _putchar - writes the char c to stdout.
 * @c: character to be written
 *
 * Return: the char written on success.
 */
int _putchar(char c)
{
	return (putchar(c));
}
