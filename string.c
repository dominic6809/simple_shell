#include "main.h"

/**
 * _strcmp - compares two strings,
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if same strings, 0 if not
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int q = 0;

	while (s1[q])
	{
		if (s1[q] != s2[q])
			return (0);
		q++;
	}

	return (1);
}
/**
 * _strlen -  finds  length  string,
 * @s: input string,
 * Return: length of string,
 */
unsigned int _strlen(char *s)
{
	unsigned int slen = 0;

	while (s[slen])
		slen++;

	return (slen);
}
/**
 * _strcpy - copies string to another string,
 * @dest: points to copied string,
 * @src: points string to copy
 * Return: points copied string,
 */
char *_strcpy(char *dest, char *src)
{
	char *cp = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (cp);
}
/**
 * _strcat - concatenates two strings
 * @dest: input string
 * @src: input string
 * Return: points resulting strings
 */
char *_strcat(char *dest, char *src)
{
	char *tmp = dest;

	while (*dest)
		dest++;

	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (tmp);
}
/**
 * _atoi - converts string to integer
 * @s: input string
 * Return: integer conversion
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int sum = 0;
	char n_flag = 0;

	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		if (*s >= '0' && *s <= '9')
		{
			n_flag = 1;
			sum = sum * 10 + (*s - '0');
		}
		else if (*s < '0' || *s > '9')
		{
			if (n_flag == 1)
				break;
		}
		s++;
	}
	if (sign < 0)
		sum = (-1 * (sum));
	return (sum);
}
