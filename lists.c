#include "shell.h"

/**
 * add_node - Adds a node at the beginning of a linked list
 * @head: A pointer to the head of the list
 * @str: The string to be added to the new node
 * @num: node index used by history
 *
 * Return: A pointer to the new head of the list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = malloc(num + 1);

	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	strncpy(new_node->str, str, num);
	new_node->str[num] = '\0';
	new_node->num = num;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}

/**
 * add_node_end - Adds a node at the end of a linked list
 * @head: A pointer to the head of the list
 * @str: The string to be added to the new node
 * @len: node index used by history
 *
 * Return: A pointer to the head of the list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = malloc(num + 1);

	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	strncpy(new_node->str, str, num);
	new_node->str[num] = '\0';
	new_node->num = num;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}

	list_t *temp = *head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new_node;

	return (*head);
}
/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}
