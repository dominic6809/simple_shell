#include "shell.h"

/**
<<<<<<< HEAD
 * _strcpy - Copies the string to the buffer pointed to by dest.
 * @src: The source string.
 * @dest: The destination string.
 * Return: A pointer to the org destination string.
=======
 * _strcpy - copies the string to the buffer pointed to by dest.
 * @src: pointer to the source string.
 * @dest: pointer to the destination string.
 * Returns: pointer to the destination string.
>>>>>>> d047200e68ae482077e4f94507316c8d16aea9d7
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
<<<<<<< HEAD
 * _strdup - Duplicates a string.
 * @str: string to duplicate
 *
=======
 * _strdup - it duplicates a string.
 * str: the sztring to duplicate.
>>>>>>> d047200e68ae482077e4f94507316c8d16aea9d7
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
<<<<<<< HEAD

	duplicate = malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

=======

	duplicate = malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];
>>>>>>> d047200e68ae482077e4f94507316c8d16aea9d7
	return (duplicate);
}

/**
<<<<<<< HEAD
 * _puts - outputs the null-terminated string pointed to by str to stdout.
 * @str: string to be printed
 *
=======
 * _puts - prints the null-terminated string pointed to by str to stdout.
 * str: string to be printed.
>>>>>>> d047200e68ae482077e4f94507316c8d16aea9d7
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
<<<<<<< HEAD
 * @c: character to be written
 *
=======
 * @c: char to be written.
>>>>>>> d047200e68ae482077e4f94507316c8d16aea9d7
 * Return: the char written on success.
 */
int _putchar(char c)
{
	return (putchar(c));
}
