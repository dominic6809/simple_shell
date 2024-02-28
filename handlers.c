#include "shell.h"

/**
 * _fputs - Custom implementation of fputs function
 * @str: String to be printed
 * @stream: Pointer to the output stream
 * Return: Number of characters printed
 */
int _fputs(const char *str, FILE *stream)
{
	int i, count = 0;

	if (str == NULL)
	return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
	fputc(str[i], stream);
	count++;
	}

	return (count);
}
/**
 * _puts - Custom implementation of puts function
 * @str: String to be printed
 * Return: Number of characters printed
 */
int _puts(char *str)
{
	int i, count = 0;

	if (str == NULL)
	return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
	putchar(str[i]);
	count++;
	}

	return (count);
}
/**
 * _getenv - Retrieves the value of the environment variable.
 * @name: The name of the environment variable.
 * Return: On success, returns a pointer to the value associated with the
 *	environment variable name. Otherwise, returns NULL.
 */
char *_getenv(const char *name)
{
	char *value = NULL;
	size_t name_length = strlen(name);
	int i;

	if (name == NULL || name_length == 0)
	return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
	if (strncmp(name, environ[i], name_length) == 0
		&& environ[i][name_length] == '=')
	{
	value = environ[i] + name_length + 1;
	break;
	}
	}

	return (value);
}
/**
 *_fputc - Writes a single character to a stream
 *@c: The character to be written
 *@stream: The stream to which the character should be written.
 *Return: The number of characters written, or EOF on error.
 */
int _fputc(int c, FILE *stream)
{
	char buf[1];

	buf[0] = c;

	return (fwrite(buf, 1, 1, stream));
}
/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string
 * Return: A pointer to the resulting string.
 */
char *_strcat(char *dest, const char *src)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';

	return (dest);
}
