#include "shell.h"

/**
 * without_comment - Removes comments from a given string
 * @in: Input string
 *
 * Return: String without comments
 */
char *without_comment(char *in)
{
    char *result;
    int i, j;

    if (in == NULL)
        return NULL;

    result = malloc(strlen(in) + 1);
    if (result == NULL)
    {
        perror("Error: Memory allocation failed");
        return NULL;
    }

    for (i = 0, j = 0; in[i] != '\0'; i++)
    {
        if (in[i] == '#')
            break;
        result[j++] = in[i];
    }

    result[j] = '\0';
    return result;
}

/**
 * shell_loop - Main shell loop for reading and executing commands
 * @datash: Input parameters
 */
void shell_loop(input_params *datash)
{
    char *line;
    char *clean_line;
    ssize_t read;
    size_t len = 0;
    int status;

    while (1)
    {
        printf("$ ");
        read = getline(&line, &len, stdin);

        if (read == -1)
        {
            if (feof(stdin))
                printf("\n");
            break;
        }

        clean_line = without_comment(line);
        if (clean_line == NULL)
            continue;

        status = check_syntax_error(datash, clean_line);
        if (status == 0)
        {
            // Execute the command
            // ...
        }

        free(clean_line);
    }

    free(line);
}
