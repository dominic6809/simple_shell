#include <stdio.h>
#include <stdlib.h>

/**
 * get_len - Get the number of digits in an integer
 * @n: Integer value
 * Return: Number of digits
 */
int get_len(int n)
{
	int len = 0;

	if (n == 0)
		return (1);

	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
/**
 * aux_itoa - Convert an integer to a string
 * @n: Integer value
 * Return: Pointer to the converted string
 */
char *aux_itoa(int n)
{
	int len = get_len(n);
	int sign = 0;
	char *str;

	if (n < 0)
	{
		sign = 1;
		len++;
		n *= -1;
	}

	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	str[len] = '\0';

	while (len > sign)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}

	if (sign)
		str[0] = '-';

	return (str);
}

/**
 * _atoi - Convert a string to an integer
 * @s: Input string
 * Return: Converted integer value
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			result = result * 10 + (s[i] - '0');
		else
			break;
	}
	return (sign * result);
}
