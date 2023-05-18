#include "shell.h"


/**
 * repeated_char - Checks if the current character at index i is repeated in the input string
 * @input: Input string
 * @i: Current index
 *
 * Return: 1 if the character is repeated, 0 otherwise
 */
int repeated_char(char *input, int i)
{
    char curr_char = input[i];
    int j = i + 1;

    while (input[j] != '\0')
    {
        if (input[j] == curr_char)
            return 1;
        j++;
    }

    return 0;
}

/**
 * error_sep_op - Checks for syntax error with separator operators
 * @input: Input string
 * @i: Current index
 * @last: Last character
 *
 * Return: 1 if there is a syntax error, 0 otherwise
 */
int error_sep_op(char *input, int i, char last)
{
    char curr_char = input[i];

    if (curr_char == ';' || curr_char == '|' || curr_char == '&')
    {
        if (curr_char == last)
            return 1;
        if (input[i + 1] == '\0')
            return 1;
        if (input[i + 1] == ';' || input[i + 1] == '|' || input[i + 1] == '&')
            return 1;
    }

    return 0;
}

/**
 * first_char - Finds the first non-space character in the input string
 * @input: Input string
 * @i: Pointer to the current index
 *
 * Return: 1 if the first non-space character is found, 0 otherwise
 */
int first_char(char *input, int *i)
{
    while (input[*i] != '\0')
    {
        if (input[*i] != ' ')
            return 1;
        (*i)++;
    }

    return 0;
}

/**
 * print_syntax_error - Prints a syntax error message
 * @datash: Input parameters
 * @input: Input string
 * @i: Current index
 * @bool: Flag indicating the type of syntax error
 */
void print_syntax_error(input_params *datash, char *input, int i, int bool)
{
    if (bool == 1)
        fprintf(stderr, "%s: %d: Syntax error: repeated character\n", datash->argv[0], datash->counter);
    else if (bool == 2)
        fprintf(stderr, "%s: %d: Syntax error: unexpected token '%c'\n", datash->argv[0], datash->counter, input[i]);
    else if (bool == 3)
        fprintf(stderr, "%s: %d: Syntax error: unexpected end of input\n", datash->argv[0], datash->counter);
}
/**
 * check_syntax_error - Checks for syntax errors in the input string
 * @datash: Input parameters
 * @input: Input string
 *
 * Return: 1 if there is a syntax error, 0 otherwise
 */
int check_syntax_error(input_params *datash, char *input)
{
    int i = 0;
    char last = ' ';

    if (!first_char(input, &i))
        return 0;

    while (input[i] != '\0')
    {
        if (repeated_char(input, i))
        {
            print_syntax_error(datash, input, i, 1);
            return 1;
        }

        if (error_sep_op(input, i, last))
        {
            print_syntax_error(datash, input, i, 2);
            return 1;
        }

        last = input[i];
        i++;
    }

    if (last == ';' || last == '|' || last == '&')
    {
        print_syntax_error(datash, input, i, 3);
        return 1;
    }

    return 0;
}
