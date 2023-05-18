#include "shell.h"

/**
 * read_line - Reads a line of input from the user
 * @i_eof: Pointer to a variable indicating end-of-file condition
 *
 * Return: Input line as a string
 */
char *read_line(int *i_eof)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);

    if (read == -1)
    {
        if (feof(stdin))
            *i_eof = 1; // Set the end-of-file condition flag
        else
        {
            perror("Error: getline failed");
            *i_eof = 0;
        }

        return NULL;
    }

    return line;
}
