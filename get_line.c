#include ”shell.h”

/**
 * bring_line - Copies the contents of the buffer to the line pointer
 * @lineptr: Pointer to the line buffer
 * @n: Pointer to the size of the line buffer
 * @buffer: Buffer containing the line
 * @j: Length of the line
 */

void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{
    if (j > 0)
    {
        if (*n < j + 1)
        {
            *n = j + 1;
            *lineptr = realloc(*lineptr, *n);
            if (*lineptr == NULL)
            {
                perror("Error: Memory allocation failed");
                exit(EXIT_FAILURE);
            }
        }
        strncpy(*lineptr, buffer, j);
    }
    else
        (*lineptr)[0] = '\0';
}

/**
 * get_line - Reads a line from a stream
 * @lineptr: Pointer to the line buffer
 * @n: Pointer to the size of the line buffer
 * @stream: File stream to read from
 *
 * Return: Number of characters read, -1 on failure or end-of-file
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
    char *buffer = NULL;
    size_t i = 0;
    size_t j = 0;
    int c;

    if (lineptr == NULL || n == NULL || stream == NULL)
        return -1;

    buffer = malloc(*n);
    if (buffer == NULL)
    {
        perror("Error: Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(stream)) != EOF)
    {
        if (i >= *n - 1)
        {
            *n += 120;
            buffer = realloc(buffer, *n);
            if (buffer == NULL)
            {
                perror("Error: Memory allocation failed");
                exit(EXIT_FAILURE);
            }
        }

        buffer[i++] = c;
        j++;

        if (c == '\n')
            break;
    }

    bring_line(lineptr, n, buffer, j);

    free(buffer);

    if (c == EOF && j == 0)
        return -1;
    else
        return j;
}
