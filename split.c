#include <shell.h>

/**
 * swap_char - Swap special characters in the input string
 * @input: Input string
 * @bool: Boolean indicating whether to swap '&' or '|'
 *
 * Return: Modified input string
 */
char *swap_char(char *input, int bool)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (bool == 1)
		{
			if (input[i] == '|')
				input[i] = '&';
			else if (input[i] == '&')
				input[i] = '|';
		}
		else
		{
			if (input[i] == '&')
				input[i] = '|';
			else if (input[i] == '|')
				input[i] = '&';
		}
	}
	return (input);
}
/**
 * add_nodes - Add separator and command nodes to the respective lists
 * @head_s: Pointer to the head of separator list
 * @head_l: Pointer to the head of command list
 * @input: Input string
 */
void add_nodes(sep_list **head_s, cmd_list **head_l, char *input)
{
	int i = 0;

	while (input[i] != '\0')
	{
		if (input[i] == ';')
			*head_s = add_sep_node_end(head_s, ';');
		else if (input[i] == '|')
			*head_s = add_sep_node_end(head_s, '|');
		else if (input[i] == '&')
			*head_s = add_sep_node_end(head_s, '&');
		else
		{
			char *line = read_line(&i);
			*head_l = add_line_node_end(head_l, line);
		}
		i++;
	}
}
/**
 * go_next - Move to the next node in the separator and command lists
 * @list_s: Pointer to the current separator node
 * @list_l: Pointer to the current command node
 * @datash: Input parameters
 */
void go_next(sep_list **list_s, cmd_list **list_l, input_params *datash)
{
	if (*list_s != NULL)
		*list_s = (*list_s)->next;

	if (*list_l != NULL)
	{
		free((*list_l)->line);
		free(*list_l);
		*list_l = NULL;
	}
	if (*list_s != NULL)
	{
		if ((*list_s)->separator == ';')
			datash->status = 0
		else if ((*list_s)->separator == '|')
			datash->status = 1;
		else if ((*list_s)->separator == '&')
			datash->status = 2;
	}
}
/**
 * split_commands - Split the input into separate commands
 * @datash: Pointer to input parameters
 * @input: Input string
 * Return: Number of commands split
 */
int split_commands(input_params *datash, char *input)
{
	int i = 0;
	char **commands = NULL;
	char *token;

	token = strtok(input, ";");
	while (token != NULL)
	{
		commands = realloc(commands, (i + 1) * sizeof(char *));
		if (commands == NULL)
		{
			perror("realloc");
			return (i);
		}
		commands[i] = strdup(token);
		if (commands[i] == NULL)
		{
			perror("strdup");
			return (i);
		}
		token = strtok(NULL, ";");
		i++;
	}
	datash->args = commands;
	return (i);
}
/**
 * split_line - Split the input line into tokens
 * @input: Input string
 * Return: Array of tokens
 */
char **split_line(char *input)
{
	int i = 0;
	char **tokens = NULL;
	char *token;

	token = strtok(input, " \t\r\n\a");

	while (token != NULL)
	{
		tokens = realloc(tokens, (i + 1) * sizeof(char *));

		if (tokens == NULL)
		{
			perror("realloc");
			return (tokens);
		}
		tokens[i] = strdup(token);

		if (tokens[i] == NULL)
		{
			perror("strdup");
			return (tokens);
		}
		token = strtok(NULL, " \t\r\n\a");
		i++;
	}
	tokens = realloc(tokens, (i + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("realloc");
		return (tokens);
	}
	tokens[i] = NULL;

	return (tokens);
}
