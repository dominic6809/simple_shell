#include "shell.h"

/**
 * _strlen - calculates the length of the string.
 * @s: pointer to the string
 * Return: length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
/**
 * _strcmp - compares two strings
 * @s1: pointer to the first string.
 * @s2: pointer to the second string.
 * Return: 0 if the strings are equal, a negative value
 * if s1 < s2, a positive value if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * starts_with - checks if a string starts with a given prefix.
 * @str: pointer to the string.
 * @prefix: pointer to the prefix.
 * Return: pointer to the rest of the string after the prefix,
 * NULL if the string does not start with the prefix.
 */
char *starts_with(const char *str, const char *prefix)
{
	while (*prefix)
	{
		if (*prefix != *str)
			return (NULL);
		prefix++;
		str++;
	}
	return ((char *)str);
}
/**
 * _strcat - concatenates two strings.
 * @dest: pointer to the destination string.
 * @src:
 * pointer to the source string.
 * Return: pointer to the destination string.
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';
	return (dest);
}
