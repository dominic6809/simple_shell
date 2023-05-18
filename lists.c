#include "shell.h"

/**
 * add_sep_node - Add a separator node to the end of the separator lists
 * @head: pointer to the head of the separator list
 * @sep: separator char to be added
 *
 * Return: Pointer to the newly added node
 */
sep_list *add_sep_node_node(sep_list **head, char sep)
{
    sep_list *new_node = (sep_list *)malloc(sizeof(sep_list));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    new_node->separator = sep;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        sep_list *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }

    return new_node;
}

/**
 * free_sep_list - Free the memory allocated for the separator list
 * @head: pointer to the head of the separator list
 */
void free_sep_list(sep_list **head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }

    sep_list *current = *head;
    sep_list *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

/**
 * add_line_node_end - Add a line node to the end of the command list
 * @head: pointer to the head of the command list
 * @line: command line to be added
 *
 * Return: Pointer to the newly added node
 */
cmd_list *add_line_node_end(cmd_list **head, char *line)
{
    cmd_list *new_node = (cmd_list *)malloc(sizeof(cmd_list));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    new_node->line = strdup(line);
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        cmd_list *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }

    return new_node;
}

/**
 * free_cmd_list - Free the memory allocated for the command list
 * @head: pointer to the head of the command list
 */
void free_cmd_list(cmd_list **head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }

    cmd_list *current = *head;
    cmd_list *next;

    while (current != NULL)
    {
        next = current->next;
        free(current->line);
        free(current);
        current = next;
    }

    *head = NULL;
}
