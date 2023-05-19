#include "shell.h"
/**
 * _atoi - converts a string to an integer
 *
 *   @str: the string to convert
 *
 *   Return: the integer value of the string
 */
int _atoi(char *str)
{
	int sign = 1, num = 0;

	/* Handle negative numbers */
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	/* Convert string to integer */
	while (*str != '\0')
	{
		if (_isdigit(*str))
		{
			num = num * 10 + (*str - '0');
		} else
		{
			break;
		}
		str++;
	}
	return (num * sign);
}
