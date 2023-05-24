#include "shell.h"

/**
 * strtow - splits a string into an arr of words.
 * @str: string to split
 * @delim: the delimiter char
 *
 * Return: a pointer to an arr of strings, or NULL
 * if an error occurs
 */

char **strtow(char *str, char *delim)
{
	char **words, *word;
	int i, j, len, word_count = 0;

	if (str == NULL || delim == NULL)
		return (NULL);
	if (words == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		len = 0;
		while (str[i + len] != *delim && str[i + len] != '\0')
			len++;

		word = malloc(sizeof(char) * (len + 1));
		if (word == NULL)
			return (NULL);

		for (j = 0; j < len; j++)
		{
			word[j] = *str++;
		}

		word[j] = '\0';
		words[i] = word;
		words = realloc(words, sizeof(char *) * (i + 2));
<<<<<<< HEAD

=======
>>>>>>> d047200e68ae482077e4f94507316c8d16aea9d7
		i += len;
	}

	words[i] = NULL;
	return (words);
}

/**
 * strtow2 - splits a string into an arr of words using a single delimiter
 * @str: string to split.
 * @delim: delimiter char.
 *
 * Return: a pointer to an arr of strings, or NULL
 * incase an error occurs.
 */
char **strtow2(char *str, char delim)
{
	char **words, *word;
<<<<<<< HEAD
	int i, j, len, numwords = 0;
=======
	int i, j, len, num_words = 0;
>>>>>>> d047200e68ae482077e4f94507316c8d16aea9d7

	if (str == NULL || str[0] == 0)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		len = 0;
<<<<<<< HEAD
		word = malloc(sizeof(char) * (len + 1));
		if (word == NULL)
=======
		words = malloc(sizeof(char) * (len + 1));
		if (words == NULL)
>>>>>>> d047200e68ae482077e4f94507316c8d16aea9d7
			return (NULL);

		for (j = 0; j < len; j++)
		{
			word[j] = str[i++];
		}

		word[j] = '\0';
		words[i] = word;
		str++;
	}

	words[j] = NULL;
	return (words);
}
