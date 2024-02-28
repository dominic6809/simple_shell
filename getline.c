#include "shell.h"

/**
 * custom_getline - Reads a line from a stream
 * @lineptrr: Pointer to a buffer that will hold the read line.
 * @n: Pointer to the size of the buffer.
 * @stream: The input stream to read from.
 * Return: The number of characters read on success, -1 on failure.
 */
ssize_t custom_getline(char **lineptrr, size_t *n, FILE *stream)
{
	char ch;
	size_t i = 0;
	const size_t initial_size = 100;

	if (*lineptrr == NULL || *n == 0)
	{
		*n = initial_size;
		*lineptrr = (char *)malloc(*n);
		if (*lineptrr == NULL)
		{
			return (-1);
		}
	}

	while ((ch = fgetc(stream)) != EOF && ch != '\n')
	{
		if (i == *n - 1)
		{
			*n *= 2;
			*lineptrr = (char *)realloc(*lineptrr, *n);
			if (*lineptrr == NULL)
			{
				free(*lineptrr);
				return (-1);
			}
		}
		(*lineptrr)[i++] = ch;
	}
	(*lineptrr)[i] = '\0';
	return (i);
}
