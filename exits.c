#include "shell.h"
/**
 * _strncpy - copies up to n chars from a source string to a destination
 * string.
 * @dest: the destination string.
 * @src: the source string.
 * @n: maximum number of chars to copy
 * Return: pointer to destination string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (i = 0; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
/**
 * _strncat - concatenates upto n chars from
 * a source string to a destination string.
 * @dest: destination string.
 * @src: the source string.
 * @n: maximum number of chars to concatenate.
 * Return: ptr to destination string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * _strchr - locates the first occurrence of a char in a sting.
 * @s: string to search
 * @c: char to locate.
 * Return: pointer to the first occurrence of the char c in the string s,
 * or NULL incase the char is not found.
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}
