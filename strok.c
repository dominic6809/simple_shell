#include "shell.h"
#include <string.h>

/**
 * custom_strtok - Breaks a string into a series of tokens.
 *
 * @str: The string to be tokenized.
 * @delim: The delimiter characters.
 *
 * Return: A pointer to the next token found in str,
 *         or NULL if there are no more tokens or if str or delim is NULL.
 */
char *
custom_strtok(char *str, const char *delim)
{
	static char *src;
	char *p, *ret = 0;

	/* If str is not NULL, set src to the start of str */
	if (str != NULL)
		src = str;

	/* If src or delim is NULL, return (NULL) */
	if (src == NULL || delim == NULL)
		return (NULL);

	/* Trim leading delimiters */
	src += strspn(src, delim);

	/* If src is an empty string after trimming, return (NULL) */
	if (*src == '\0')
		return (NULL);

	/* Find next delimiter */
	p = strpbrk(src, delim);

	/*
	* If delimiter is found, replace with
	* a null character and move src past it
	*/
	if (p != NULL)
{
		*p = '\0';
		ret = src;
		src = p + 1;
	} else
{
		/* If no more delimiters, return remainder of string as last token */
		ret = src;
		src = NULL;
	}

	/* Trim trailing delimiters */
	ret += strspn(ret, delim);

	return (ret);
}
