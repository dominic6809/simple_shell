#include "shell.h"

/**
 * _strcpy - copies the string to the buffer pointed to by dest.
 * @src: pointer to the string.
 * @dest: pointer to the destination string.
 * Returns: pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
	char *orig_dest = dest;

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (orig_dest);
}

/**
 * _strdup - duplicates the string pointed to by src,
 * allocating mem for the new string using malloc.
 * @src: pointer to the source string.
 *
 * Returns: a pointer to the duplicated string, or (NULL)
 * incase the allocation fails.
 */

char *_strdup(const char *src)
{
	size_t len = _strlen(src);
	char *dup = malloc(len + 1);

	if (!dup)
	{
		return (NULL);
	}

	_strcpy(dup, (char *)src);

	return (dup);
}
/**
 * _puts - outputs the null-terminated string pointed to by str to stdout.
 * Return: nothing.
 */
void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str++);
	}
	_putchar('\n');
}

/**
 * _putchar - writes the char c to stdout.
 *
 * Returns: the char written.
 */
int _putchar(char c)
{
	return (putchar(c));
}
