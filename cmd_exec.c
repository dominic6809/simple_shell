#include "shell.h"

/**
 * is_cdir - Check if the path is a current directory reference
 * @path: Path to check
 * @i: Pointer to an integer indicating the index
 *
 * Return: 1 if the path is a current directory reference, 0 otherwise
 */

int is_cdir(char *path, int *i)
{
    if (path[*i] == '.' && (*i == 0 || path[*i - 1] == '/'))
    {
        if (path[*i + 1] == '\0' || path[*i + 1] == '/')
        {
            *i += 1;
            return 1;
        }
        else if (path[*i + 1] == '.' && (path[*i + 2] == '\0' || path[*i + 2] == '/'))
        {
            *i += 2;
            return 1;
        }
    }
    return 0;
}

/**
 * _which - Locate a command in the PATH environment variable
 * @cmd: Command to locate
 * @_environ: Environment variable
 *
 * Return: Full path to the command if found, NULL otherwise
 */

char *_which(char *cmd, char **_environ)
{
    char *path = getenv("PATH");
    char *token, *dir, *path_copy;
    int i = 0;

    if (path == NULL)
        return NULL;

    path_copy = strdup(path);
    if (path_copy == NULL)
        return NULL;

    token = strtok(path_copy, ":");
    while (token != NULL)
    {
        dir = malloc(strlen(token) + strlen(cmd) + 2);
        if (dir == NULL)
        {
            free(path_copy);
            return NULL;
        }

        strcpy(dir, token);
        strcat(dir, "/");
        strcat(dir, cmd);

        if (access(dir, X_OK) == 0)
        {
            free(path_copy);
            return dir;
        }

        free(dir);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

/**
 * is_executable - Check if the command is executable
 * @datash: Input parameters
 *
 * Return: 1 if the command is executable, 0 otherwise
 */

int is_executable(input_params *datash)
{
    if (access(datash->args[0], X_OK) == 0)
        return 1;

    char *cmd_path = _which(datash->args[0], datash->_environ);
    if (cmd_path != NULL)
    {
        free(datash->args[0]);
        datash->args[0] = cmd_path;
        return 1;
    }

    return 0;
}

/**
 * check_error_cmd - Check if the command is valid and executable
 * @dir: Directory path
 * @datash: Pointer to input parameters
 * Return: 1 if there is an error, 0 otherwise
 */
int check_error_cmd(char *dir, input_params *datash)
{
    if (access(dir, F_OK) == -1)
    {
        fprintf(stderr, "%s: command not found\n", datash->args[0]);
        return 1;
    }
    else if (access(dir, X_OK) == -1)
    {
        fprintf(stderr, "%s: Permission denied\n", datash->args[0]);
        return 1;
    }

    return 0;
}

/**
 * cmd_exec - Execute the command
 * @datash: Pointer to input parameters
 * Return: 1 on success, 0 on failure
 */
int cmd_exec(input_params *datash)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        return 0;
    }
    else if (child_pid == 0)
    {
        if (execve(datash->args[0], datash->args, datash->_environ) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(child_pid, &status, 0);
        if (WIFEXITED(status))
            return 1;
        else
            return 0;
    }

    return 0;
}
