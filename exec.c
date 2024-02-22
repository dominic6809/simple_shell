#include "shell.h" // Include custom shell header
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define MAX_ARG_LENGTH 64

char *program_name; // Variable to store the program name

// Function prototypes
int execute(char **args);
int execute_exit(char **args);
int execute_env(void);
int execute_command(char **args);

int main(int argc, char **argv) {
    program_name = strdup(argv[0]); // Store the program name
    char input[MAX_ARGS][MAX_ARG_LENGTH];
    char *args[MAX_ARGS];

    while (1) {
        shell_prompt(); // Display shell prompt
        if (shell_read(input[0], MAX_ARG_LENGTH) == NULL) {
            break; // Break the loop if no input is provided
        }

        // Tokenize the input
        char *token = strtok(input[0], " \n");
        int i = 0;
        while (token != NULL) {
            args[i] = strdup(token);
            token = strtok(NULL, " \n");
            i++;
        }
        args[i] = NULL;

        // Execute built-in commands or external commands
        if (strcmp(args[0], "exit") == 0) {
            execute_exit(args);
        } else if (strcmp(args[0], "env") == 0) {
            execute_env();
        } else {
            execute(args);
        }

        // Free memory allocated for arguments
        for (int j = 0; j < i; j++) {
            free(args[j]);
        }
    }

    free(program_name); // Free memory allocated for program name
    return 0;
}

// Function to execute commands
int execute(char **args) {
    pid_t pid = fork();
    int status;

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp"); // Print error if execvp fails
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        // Error forking process
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

// Function to handle "exit" command
int execute_exit(char **args) {
    if (args[1] != NULL) {
        exit(atoi(args[1])); // Exit with specified status code
    } else {
        exit(EXIT_SUCCESS); // Exit with success status
    }
}

// Function to handle "env" command
int execute_env(void) {
    extern char **environ;
    for (char **env = environ; *env != NULL; env++) {
        shell_print(*env); // Print environment variables
    }
    return 1;
}
