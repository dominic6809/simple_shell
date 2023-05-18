#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * check_env - Check and replace environment variables in the input string
 * @h: Pointer to the head of environment variables list
 * @in: Input string
 * @parameters: Input parameters
 */
void check_env(varz_list **h, char *in, input_params *parameters)
{
	varz_list *tmp = *h;

	while (tmp != NULL)
	{
		char *env_val = getenv(tmp->name);

		if (env_val != NULL)
		{
			char *var = malloc(strlen(tmp->name) + 3);

			sprintf(var, "$%s", tmp->name);

			char *replace_val = strdup(env_val);

			replace_substr(in, var, replace_val);
			free(replace_val);
			free(var);
		}
		tmp = tmp->next;
	}
}
/**
 * check_vars - Check and replace variables in the input string
 * @h: Pointer to the head of variables list
 * @in: Input string
 * @st: Start of variable substring
 * @parameters: Input parameters
 *
 * Return: 1 if variable is found and replaced, 0 otherwise
 */
int check_vars(varz_list **h, char *in, char *st, input_params *parameters)
{
	char *end = strchr(st, '}');

	if (end == NULL)
		return (0);

	size_t var_len = end - st - 1;
	char *var_name = malloc(var_len + 1);

	strncpy(var_name, st + 1, var_len);
	var_name[var_len] = '\0';

	varz_list *tmp = *h;

	while (tmp != NULL)
	{
		if (strcmp(tmp->name, var_name) == 0)
		{
			char *var = malloc(var_len + 4);

			sprintf(var, "${%s}", tmp->name);

			char *replace_val = strdup(tmp->value);

			replace_substr(in, var, replace_val);
			free(replace_val);
			free(var);
			free(var_name);

			return (1);
		}
		tmp = tmp->next;
	}
	free(var_name);
	return (0);
}
/**
 * replaced_input - Replace the original input string with the new input string
 * @head: Pointer to the head of variables list
 * @input: Original input string
 * @new_input: New input string
 * @nlen: Length of the new input string
 *
 * Return: Replaced input string
 */
char *replaced_input(varz_list **head, char *input, char *new_input, int nlen)
{
	char *result = NULL;
	int rlen = strlen(input) - nlen + 1;

	result = malloc(rlen);
	char *ptr = strstr(input, new_input);

	strncpy(result, input, ptr - input);
	result[ptr - input] = '\0';

	strcat(result, &input[ptr - input + nlen]);

	return (result);
}
/**
 * rep_var - Replace variables in the input string
 * @input: Input string
 * @datash: Input parameters
 *
 * Return: Modified input string with variables replaced
 */
char *rep_var(char *input, input_params *datash)
{
	char *result = strdup(input);

	varz_list *tmp = datash->var_list;

	while (tmp != NULL)
	{
		char *var = malloc(strlen(tmp->name) + 4);

		sprintf(var, "${%s}", tmp->name);

		char *value = tmp->value != NULL ? strdup(tmp->value) : "";

		result = replaced_input(&(datash->var_list), result, var, strlen(var));
		result = rep_input(&(datash->var_lst), result, tmp->name, strlen(tmp->name));
		result = replaced_input(&(datash->var_list), result, value, strlen(value));

		free(var);
		tmp = tmp->next;
	}
	return (result);
}
