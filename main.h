#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#define MAX_COMMAND_LEN 1024
#define MAX_TOKENS 64
#define DELIMITER " \t\n"

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>

extern char **environ;

int custom_hello(void);
int prompt(char **line);
void print_prompt(void);
ssize_t write(int fd, const void *buf, size_t count);
char **parse_command(char *command);
int builtin_exit(void);
int builtin_env(char **env);
int execute(char **args);
char **split_line(char *line);
void exit_shell(char **args);
int _splitPATH(char *str);
int _PATHstrcmp(const char *s1, const char *s2);
char *_getenv(const char *name);
int _env(void);
char *program_name;
char *get_command_path(char *command);
char *build_command_path(char *directory, char *command);
int builtin_cd(char **args);
int execute_exit(char **args);
int execute_command(char **args);
int execute_env(void);
int handle_semicolon(char *line);
int _putenv(char *string);
int myunsetenv(char *variable);
int mysetenv(char *variable, char *value, int overwrite);
int is_exit_command(char **args);
int get_exit_status(char **args);
int cd(char *directory);

/* helper function prototypes */
int _atoi(const char *str);
void free_args(char **args);
size_t _strlen(const char *s);
int _strcmp(const char *str1, const char *str2);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strchr(const char *str, int c);
char *_strdup(const char *str);
char *_strcpy(char *destination, const char *source);
int _putchar(char c);
int _puts(char *str);
int _fputs(const char *str, FILE *stream);
int _fputc(int c, FILE *stream);
char *_strcat(char *dest, const char *src);
int _fputc(int c, FILE *stream);
void *myrealloc(void *ptr, size_t size);

#endif /* MAIN_H */
