#include "shell.h"

/**
 * strtow - splits a string into an arr of words.
 * @str: string to split.
 * @delim: delimiter char
 * Return: a pointer to an arr of strings, or NULL
 * incase of an error.
 */
char **strtow(char *str, char *delim)
{
	char **words, *word;
	int i, j, word_count = 0;

	if (str == NULL || delim == NULL)
		return (NULL);
	if (words == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		int len = 0;
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
		i += len;
	}
	words[i] = NULL;
	return (words);
}
/**
 * strtow2 - splits a string into an arr of words using a single delimiter
 * @str: string to split.
 * @delim: delimiter char.
 * Return: a pointer to an arr of strings, or NULL
 * incase of an error.
 */
char **strtow2(char *str, char delim)
{
	char **words, *word;
	int i, j, len, numwords = 0;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		len = 0;
		word = malloc(sizeof(char) * (len + 1));
		if (word == NULL)
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
