#include "shell.h"

/**
 * _strchr - locate character string
 * @str: string to be searched
 * @d: character to be located
 *
 * Return: pointer to first occurrence of character in str
 * otherwise NULL if not found
 */
char *_strchr(const char *str, int d)
{
	while (*str != '\0')
	{
		if (*str == d)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
/**
 * _strdup - duplicate a string
 * @str: source string to be duplicated
 * Return: pointer to newly allocated string, otherwise NULL
 */
char *_strdup(const char *str)
{
	size_t length = _strlen(str);
	char *duplicat;

	duplicat = (char *)malloc((length + 1) * sizeof(char));

	if (str == NULL)
		return (NULL);

	if (duplicat == NULL)
		return (NULL);

	_strcpy(duplicat, str);
	return (duplicat);
}

/**
 * _strcmp - compares two strings
 * @str1: char type
 * @str2: char type
 * Return: integer value
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
/**
 * _atoi - converts a string to an integer
 * @str: string to convert
 * Return: result
 */
int _atoi(const char *str)
{
	int sign = 1;
	int result = 0;
	int k = 0;

	while (str[k] == ' ')
		k++;

	if (str[k] == '-' || str[k] == '+')
	{
		if (str[k] == '-')
			sign = -1;
		k++;
	}
	while (isdigit(str[k]))
	{
		result = result * 10 + (str[k] - '0');
		k++;
	}
	return (sign * result);
}
/**
 * _strncmp - compare at most n characters of two strings
 * @s1: first string
 * @s2: second string
 * @n: max number of chars to compare
 * Return: integer...
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t k;

	for (k = 0; k < n && s1[k] && s2[k] && s1[k] == s2[k]; k++)
		;

	return (k == n ? 0 : (s1[k] - s2[k]));
}
