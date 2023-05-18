#include "shell.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the resulting string
 */
char *_strcat(char *dest, const char *src)
{
    char *ptr = dest;

    while (*ptr != '\0')
        ptr++;

    while (*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }

    *ptr = '\0';

    return dest;
}

/**
 * _strcpy - Copies a string
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the resulting string
 */
char *_strcpy(char *dest, char *src)
{
    char *ptr = dest;

    while (*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }

    *ptr = '\0';

    return dest;
}

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: Difference between the ASCII values of the first differing characters
 */
int _strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        
        s1++;
        s2++;
    }

    return 0;
}

/**
 * _strchr - Locates the first occurrence of a character in a string
 * @s: String to search
 * @c: Character to find
 *
 * Return: Pointer to the first occurrence of the character, or NULL if not found
 */
char *_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return s;
        
        s++;
    }

    if (c == '\0')
        return s;

    return NULL;
}

/**
 * _strspn - Calculates the length of the initial segment of a string
 *            consisting only of characters from another string
 * @s: String to be scanned
 * @accept: String containing the characters to match
 *
 * Return: Number of characters in the initial segment that match
 */
int _strspn(char *s, char *accept)
{
    int count = 0;
    int found = 0;

    while (*s != '\0')
    {
        found = 0;
        while (*accept != '\0')
        {
            if (*s == *accept)
            {
                found = 1;
                break;
            }
            accept++;
        }
        if (found == 0)
            break;
        count++;
        s++;
        accept = accept - count;
    }

    return count;
}

