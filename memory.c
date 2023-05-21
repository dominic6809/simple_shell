#include "shell.h"
#include <stddef.h>

/**
 * bfree - Frees a pointer and sets it to NULL
 * @ptr: Address of the pointer to free
 *
 * Return: 1 if success, 0 if ptr is NULL or *ptr is NULL
 */
int bfree(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;

		return (1);
	}
	else
	{
		return (0);
	}
}
