#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#define BUFF_SIZE 1024
#define TOKEN_BUFF_SIZE 128
#define TOKEN_DELIMITER " \t\r\n\a"

/* The "environment" is an array of pointers to strings */
extern char **environ;

/**
 * struct parameters - struct that contains all relevant parameters on runtime
 * @argv: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct parameters
{
	char **argv;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} input_params;

/**
 * struct varible_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct varible_list
{
	int len_var;
	char *val;
	int len_val;
	struct varible_list *next;
} varz_list;

/**
 * struct separator_list - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct separator_list
{
	char separator;
	struct separator_list *next;
} sep_list;

/**
 * struct cli_list - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct cli_list
{
	char *line;
	struct cli_list *next;
} cmd_list;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: parameters type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(input_params *datash);
} builtin_t;

/*get_builtin.c*/
int (*get_builtin(char *cmd))(input_params *datash);

/*mem.c*/
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/*str.c*/
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/*str1.c*/
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/*str2.c*/
void rev_string(char *s);

/*lists.c */
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
cmd_list *add_line_node_end(cmd_list **head, char *line);
void free_cmd_list(cmd_list **head);

/*lists1.c*/
varz_list *add_rvar_node(varz_list **head, int lvar, char *var, int lval);
void free_rvar_list(varz_list **head);

/*error.c */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(input_params *datash, char *input, int i, int bool);
int check_syntax_error(input_params *datash, char *input);

/*error1.c*/
char *strcat_cd(input_params *, char *, char *, char *);
char *error_get_cd(input_params *datash);
char *error_not_found(input_params *datash);
char *error_exit_shell(input_params *datash);

/*error2.c*/
char *error_get_alias(char **args);
char *error_env(input_params *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(input_params *datash);

/*get_error.c*/ 
int get_error(input_params *datash, int eval);

/* get_sigint.c */
void get_sigint(int sig);

/*aux_help.c*/
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);

/*help1.c*/
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void)

/*get_help.c */
int get_help(input_params *datash);

/*exec_line */
int exec_line(input_params *datash);

/* read_line.c*/
char *read_line(int *i_eof);

/*cmd_exec.c*/ 
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(input_params *datash);
int check_error_cmd(char *dir, input_params *datash);
int cmd_exec(input_params *datash);

/*get_line.c*/ 
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);

/*shell_loop.c*/
char *without_comment(char *in);
void shell_loop(input_params *datash);

/*split.c */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, cmd_list **head_l, char *input);
void go_next(sep_list **list_s, cmd_list **list_l, input_params *datash);
int split_commands(input_params *datash, char *input);
char **split_line(char *input);

/*rep_var.c*/
void check_env(varz_list **h, char *in, input_params *parameters);
int check_vars(varz_list **h, char *in, char *st, input_params *parameters);
char *replaced_input(varz_list **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, input_params *datash);

/* env.c*/ 
char *_getenv(const char *name, char **_environ);
int _env(input_params *datash)

/*env1.c*/
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, input_params *datash);
int _setenv(input_params *datash);
int _unsetenv(input_params *datash);

/*cd_shell.c*/ 
int cd_shell(input_params *datash);

/*cd.c*/ 
void cd_dot(input_params *datash);
void cd_to(input_params *datash);
void cd_previous(input_params *datash);
void cd_to_home(input_params *datash);

/*stdlib.c */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

/*exit.c */
int exit_shell(input_params *datash);

#endif
