#include "main.h"

/**
 * _putchar - writes the character c to standard output
 * @c: character to print
 * Return: 1 on success, elsewhere -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strlen - Calculate the length of a string
 * @s: Pointer to the string to calculate the length of string
 * Return: Length of the string
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}
/**
 * free_args - Free the memory allocated for an array of strings
 * @args: Array of strings to free memory
 * Return: void as a return type
 */
void free_args(char **args)
{
	char **temp_ = args;

	while (*temp_)
	{
		free(*temp_);
		temp_++;
	}
	free(args);
}

/**
 * _strncpy - copies a string
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of characters to copy
 *
 * Return: pointer to destination buffer
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t k;

	for (k = 0; k < n && src[k] != '\0'; k++)
		dest[k] = src[k];

	for (; k < n; k++)
		dest[k] = '\0';

	return (dest);
}
/**
 * _strcpy - copies a string
 * @destination: string destination
 * @source: source string
 * Return: destination
 */
char *_strcpy(char *destination, const char *source)
{
	char *ptr = destination;

	while (*source != '\0')
	{
		*ptr++ = *source++;
	}
	*ptr = '\0';

	return (destination);
}
