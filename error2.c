#include "shell.h"

/**
 * error_get_alias - Generates the error message for 'alias' command with invalid arguments
 * @args: Command arguments
 *
 * Return: Error message
 */
char *error_get_alias(char **args)
{
    char *error = malloc(128 * sizeof(char));

    if (error == NULL)
    {
        perror("Error: Memory allocation failed");
        return NULL;
    }

    sprintf(error, "usage: %s name[='string'] ...", args[0]);

    return error;
}

/**
 * error_env - Generates the error message for environment variable-related errors
 * @datash: Input parameters
 *
 * Return: Error message
 */
char *error_env(input_params *datash)
{
    char *error = malloc(128 * sizeof(char));

    if (error == NULL)
    {
        perror("Error: Memory allocation failed");
        return NULL;
    }

    sprintf(error, "%s: %d: %s: not found", datash->argv[0], datash->counter, datash->args[1]);

    return error;
}

/**
 * error_syntax - Generates the error message for syntax errors in command arguments
 * @args: Command arguments
 *
 * Return: Error message
 */
char *error_syntax(char **args)
{
    char *error = malloc(128 * sizeof(char));

    if (error == NULL)
    {
        perror("Error: Memory allocation failed");
        return NULL;
    }

    sprintf(error, "Syntax error near unexpected token '%s'", args[0]);

    return error;
}

/**
 * error_permission - Generates the error message for permission-related errors
 * @args: Command arguments
 *
 * Return: Error message
 */
char *error_permission(char **args)
{
    char *error = malloc(128 * sizeof(char));

    if (error == NULL)
    {
        perror("Error: Memory allocation failed");
        return NULL;
    }

    sprintf(error, "%s: %s: Permission denied", args[0], args[1]);

    return error;
}

/**
 * error_path_126 - Generates the error message for executable file not found
 * @datash: Input parameters
 *
 * Return: Error message
 */
char *error_path_126(input_params *datash)
{
    char *error = malloc(128 * sizeof(char));

    if (error == NULL)
    {
        perror("Error: Memory allocation failed");
        return NULL;
    }

    sprintf(error, "%s: %d: %s: not found", datash->argv[0], datash->counter, datash->args[0]);

    return error;
}
