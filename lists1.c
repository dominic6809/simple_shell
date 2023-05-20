#include "shell.h"

/**
 * list_len - Returns the number of elements in a linked list.
 * @list: A pointer to the head of the linked list.
 * Return: The number of elements in the list.
 */
size_t list_len(const list_t *list)
{
	size_t count = 0;

	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

/**
 * list_to_strings - Converts linked list of strings into  array of strings.
 * @list: A pointer to the head of the linked list.
 * Return: A NULL-terminated array of strings.
 */
char **list_to_strings(list_t *list)
{
	size_t len = list_len(list);
	char **strings = malloc(sizeof(char *) * (len + 1));
	size_t i;

	if (strings == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		strings[i] = _strdup(list->str);
		if (strings[i] == NULL)
		{
			ffree(strings);
			return (NULL);
		}
		list = list->next;
	}
	strings[i] = NULL;

	return (strings);
}

/**
 * print_list - Prints the contents of a linked list to standard output.
 * @list: A pointer to the head of the linked list.
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *list)
{
	size_t count = 0;

	while (list)
	{
		_puts(list->str);
		_putchar('\n');
		count++;
		list = list->next;
	}
	return (count);
}
/**
 * node_starts_with - searches for a node starting with a certain string
 * @head: pointer to the head of the list
 * @start: the string to search for at the beginning of nodes
 * @type: specifies if the string to search for is a command or an argument
 *
 * Return: pointer to the first node found starting with the given string,
 *         NULL if no such node exists.
 */
list_t *node_starts_with(list_t *head, char *start, char type)
{
	list_t *node = head;
	size_t len = strlen(start);

	while (node != NULL)
	{
		if (type == 'c')
		{
			if (starts_with(node->str, start))
				return (node);
		}
		if (type == 'a')
		{
			if (starts_with(node->str, start))
				return (node);
		}
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node in a list
 * @head: pointer to the head of the list
 * @node: pointer to the node whose index is to be found
 *
 * Return: the index of the node in the list, -1 if the node is not in the list
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	list_t *curr = head;
	ssize_t index = 0;

	while (curr != NULL)
	{
		if (curr == node)
			return (index);

		index++;
		curr = curr->next;
	}
	return (-1);
}

