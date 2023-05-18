#include "shell.h"

/**
 * add_rvar_node - Add a variable node to the variable list
 * @head: pointer to the head of the variable list
 * @lvar: length of the variable
 * @var: name of the variable
 * @lval: length of the value
 *
 * Return: Pointer to the newly added node
 */
varz_list *add_rvar_node(varz_list **head, int lvar, char *var, int lval)
{
    varz_list *new_node = (varz_list *)malloc(sizeof(varz_list));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    new_node->len_var = lvar;
    new_node->val = strdup(var);
    new_node->len_val = lval;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        varz_list *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }

    return new_node;
}

/**
 * free_rvar_list - Free the memory allocated for the variable list
 * @head: pointer to the head of the variable list
 */
void free_rvar_list(varz_list **head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }

    varz_list *current = *head;
    varz_list *next;

    while (current != NULL)
    {
        next = current->next;
        free(current->val);
        free(current);
        current = next;
    }

    *head = NULL;
}
