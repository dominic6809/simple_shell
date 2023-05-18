#include "shell.h"


/**
 * _strdup - Duplicates a string
 * @s: Source string
 *
 * Return: Pointer to the newly allocated duplicated string, or NULL on failure
 */
char *_strdup(const char *s)
{
    if (s == NULL)
        return NULL;

    int len = strlen(s) + 1;
    char *dup = malloc(len);
    if (dup == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    strcpy(dup, s);
    return dup;
}

/**
 * _strlen - Calculates the length of a string
 * @s: String
 *
 * Return: Length of the string
 */
int _strlen(const char *s)
{
    int len = 0;

    while (*s != '\0')
    {
        len++;
        s++;
    }

    return len;
}

/**
 * cmp_chars - Compares characters of a string with a delimiter
 * @str: String to compare
 * @delim: Delimiter string
 *
 * Return: 1 if any character of @str matches any character of @delim, 0 otherwise
 */
int cmp_chars(char str[], const char *delim)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0; delim[j] != '\0'; j++)
        {
            if (str[i] == delim[j])
                return 1;
        }
    }

    return 0;
}

/**
 * _strtok - Breaks a string into a sequence of tokens
 * @str: String to tokenize
 * @delim: Delimiter string
 *
 * Return: Pointer to the next token, or NULL if there are no more tokens
 */
char *_strtok(char str[], const char *delim)
{
    static char *next_token = NULL;
    if (str != NULL)
        next_token = str;

    if (next_token == NULL || *next_token == '\0')
        return NULL;

    char *token_start = next_token;
    char *token_end = strstr(next_token, delim);

    if (token_end != NULL)
    {
        next_token = token_end + strlen(delim);
        *token_end = '\0';
    }
    else
    {
        next_token = NULL;
    }

    return token_start;
}

/**
 * _isdigit - Checks if a string contains only digits
 * @s: String to check
 *
 * Return: 1 if the string contains only digits, 0 otherwise
 */
int _isdigit(const char *s)
{
    if (s == NULL)
        return 0;

    while (*s != '\0')
    {
        if (!isdigit(*s))
            return 0;
        s++;
    }

    return 1;
}

