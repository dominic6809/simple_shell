#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

void handle_exit(char **tokens);
void handle_cd(char **tokens);
void print_prompt(void);
ssize_t custom_getLine(char **lineptrr, size_t *n, FILE *stream);
pid_t create_process(void);
int execute_command(char *command, char **args, char *program_name);
char *resolve_path(char *command);
int wait_for_process(pid_t pid);
void handle_signal(int signal);
int terminate_process(pid_t pid);
void prompt(void);
void handle(int signals);
void _EOF(char *buffer);
void shell_exit(char **command);
void bety(char **command, char *name, char **env, int round);
int cd_dir(const char *path);
void execute(char **command, char *name, char **env, int round3);
void print_env(char **env);
char **get_PATH(char **env);
void msgerror(char *name, int round4, char **command);
char **tokenizer(char *buffer, const char *s);
void free_dp(char **command);
void free_exit(char **command);
void sigint_handler(int sig);
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *custom_strok(char *str, const char *delim);
char **command_parser(char *line, const char *delimiter);
int builtin_env(void);

#endif
