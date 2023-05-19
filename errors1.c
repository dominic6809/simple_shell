#include "header_file.h"

/* file name: error_utils.c */

/**
 * erratoi - changes a string to an integer.
 * @str: string to be changed.
 *
 * Return: integer value of the string.
 */
int _erratoi(char *str)
{
	int i, result;

	result = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		else
		{
			_puts("error: invalid argument\n");
			return (-1);
		}
	}
	return (result);
}

/**
 * print_error - outputs an error.
 * @info: a pointer to the info_t struct.
 * @msg: error message to print.
 */
void print_error(info_t *info, char *msg)
{
	_putsfd(info->name, 2);
	_putsfd(":", 2);
	_putsfd(msg, 2);
}
/**
 * print_d - prints a number with leading zeros
 * @n: number to print.
 * @num_digits: minimum number of digits to print.
 * Return: number of digits printed.
 */
int print_d(int n, int num_digits)
{
	int i, num_zeros;

	num_zeros = num_digits - _numlen(n);
	if (num_zeros > 0)
	{
		for (i = 0; i < num_zeros; i++)
			_putchar('0');
	}
	return (_putnbr(n));
}
/**
 * convert_number - changes a number to a string with a given base
 * @num: the number to convert.
 * @base: base to convert to.
 * @uppercase: whether to use uppercase or lowercase letters.
 * Return: pointer to the string representation of the number.
 */
char *convert_number(long int num, int base, int uppercase)
{
	static char buffer[50];
	char *ptr;
	char hex_digits[] = "0123456789abcdef";
	char HEX_DIGITS[] = "0123456789ABCDEF";

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		if (uppercase)
			*--ptr = HEX_DIGITS[num % base];
		else
			*--ptr = hex_digits[num % base];
		num /= base;
	} while (num != 0);
	return (ptr);
}
/**
 * remove_comments - ommits comments from a string.
 * @str: the string to remove comments from.
 */
void remove_comments(char *str)
{
	int i, in_comment, len;

	len = _strlen(str);
	in_comment = 0;

	for (i = 0; i < len; i++)
	{
		if (in_comment)
		{
			if (str[i] == '\n')
				in_comment = 0;
			else
				str[i] = '';
		}
		else
		{
			if (str[i] == '#')
				in_comment = 1;
		}
	}
}
