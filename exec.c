#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define MAX_ARG_LENGTH 64

char *program_name;

int execute(char **args);
int execute_exit(char **args);
int execute_env(void);
int execute_command(char **args);

/**
 * main - Entry point of the shell program
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 * Return: Always 0
 */
int main(int argc, char **argv)
{
    program_name = strdup(argv[0]);
    char input[MAX_ARGS][MAX_ARG_LENGTH];
    char *args[MAX_ARGS];

    while (1)
    {
        shell_prompt();
        if (shell_read(input[0], MAX_ARG_LENGTH) == NULL)
        {
            break;
        }

        char *token = strtok(input[0], " \n");
        int i = 0;
        while (token != NULL)
        {
            args[i] = strdup(token);
            token = strtok(NULL, " \n");
            i++;
        }
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0)
        {
            execute_exit(args);
        }
        else if (strcmp(args[0], "env") == 0)
        {
            execute_env();
        }
        else
        {
            execute(args);
        }

        for (int j = 0; j < i; j++)
        {
            free(args[j]);
        }
    }

    free(program_name);
    return 0;
}

/**
 * execute - Execute command
 * @args: Array of strings containing command and arguments
 * Return: Always 1
 */
int execute(char **args)
{
    pid_t pid = fork();
    int status;

    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

/**
 * execute_exit - Handle the "exit" command
 * @args: Array of strings containing command and arguments
 * Return: Void
 */
int execute_exit(char **args)
{
    if (args[1] != NULL)
    {
        exit(atoi(args[1]));
    }
    else
    {
        exit(EXIT_SUCCESS);
    }
}

/**
 * execute_env - Handle the "env" command
 * Return: Always 1
 */
int execute_env(void)
{
    extern char **environ;
    for (char **env = environ; *env != NULL; env++)
    {
        shell_print(*env);
    }
    return 1;
}
