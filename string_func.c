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

	word_count = count_words(str, delim);

	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0; i < word_count; i++)
	{
		len = word_len(&str[0], delim);
		word = malloc(sizeof(char) * (len + 1));
		if (word == NULL)
			return (NULL);

		for (j = 0; j < len; j++)
		{
			word[j] = *str++;
		}

		word[j] = '\0';
		words[i] = word;
		str += delim_len(&str[0], delim);
	}

	words[word_count] = NULL;
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
	int i, j, len, word_count = 0;

	if (str == NULL)
		return (NULL);

	word_count = count_words(str, delim);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0; i < word_count; i++)
	{
		len = word_len2(&str[0], delim);
		word = malloc(sizeof(char) * (len + 1));
		if (word == NULL)
			return (NULL);

		for (j = 0; j < len; j++)
		{
			word[j] = *str++;
		}

		word[j] = '\0';
		words[i] = word;
		str++;
	}

	words[word_count] = NULL;
	return (words);
}
