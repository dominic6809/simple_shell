#include "shell.h"

/**
 * get_error - Retrieves the error code based on evaluation result
 * @datash: Input parameters
 * @eval: Evaluation result
 *
 * Return: Error code
 */
int get_error(input_params *datash, int eval)
{
    int error = 0;

    if (eval == 127)
    {
        fprintf(stderr, "%s: %d: %s: not found\n", datash->argv[0], datash->counter, datash->args[0]);
        error = 127;
    }
    else if (eval == 2)
    {
        fprintf(stderr, "%s: %d: exit: Illegal number: %s\n", datash->argv[0], datash->counter, datash->args[1]);
        error = 2;
    }
    else if (eval == 126)
    {
        fprintf(stderr, "%s: %d: %s: Permission denied\n", datash->argv[0], datash->counter, datash->args[0]);
        error = 126;
    }

    return error;
}
