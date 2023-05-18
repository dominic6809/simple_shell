#include "shell.h"


/**
 * strcat_cd - Concatenates strings to form the error message for 'cd' command
 * @datash: Input parameters
 * @cmd: Command name
 * @arg: Argument
 * @msg: Error message
 *
 * Return: Concatenated error message
 */
char *strcat_cd(input_params *datash, char *cmd, char *arg, char *msg)
{
    int len_cmd = strlen(cmd);
    int len_arg = strlen(arg);
    int len_msg = strlen(msg);
    char *error = malloc((len_cmd + len_arg + len_msg + 4) * sizeof(char));

    if (error == NULL)
    {
        perror("Error: Memory allocation failed");
        return NULL;
    }

    strcpy(error, datash->argv[0]);
    strcat(error, ": ");
    strcat(error, cmd);
    strcat(error, ": ");
    strcat(error, arg);
    strcat(error, ": ");
    strcat(error, msg);

    return error;
}

/**
 * error_get_cd - Generates the error message for 'cd' command with invalid argument
 * @datash: Input parameters
 *
 * Return: Error message
 */
char *error_get_cd(input_params *datash)
{
    return strcat_cd(datash, "cd", "", "Can't read directory");
}

/**
 * error_not_found - Generates the error message for command not found
 * @datash: Input parameters
 *
 * Return: Error message
 */
char *error_not_found(input_params *datash)
{
    return strcat_cd(datash, datash->args[0], "", "not found");
}

/**
 * error_exit_shell - Generates the error message for exit command with invalid argument
 * @datash: Input parameters
 *
 * Return: Error message
 */
char *error_exit_shell(input_params *datash)
{
    return strcat_cd(datash, "exit", "", "Illegal number");
}
