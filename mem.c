#include "shell.h"

/**
 * _memset - fills the first n bytes of the memory area pointed to by s with
 * the constant byte b.
 *
 * @s: pointer to the memory area to be filled.
 * @b: the constant byte to fill the memory with.
 * @n: number of bytes to be filled.
 *
 * Return: a ponter to the memory area s.
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees two-dimensional arr of strings and sets the pointers to NULL
 *
 * @arr: pointer to the two-dimensional array of strings.
 */
void ffree(char **arr)
{
	int i;

	if (arr == NULL)
		return;
	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
}

/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: pointer to the memory previouslyallocated.
 * @old_size: size of allocated space for ptr.
 * @new_size: new size to be allocated.
 * Return: pointer to the newly allocated mem or NULL,
 * if new_size is 0 and ptr i otherwise NULL if the function
 * fails to allocate the requested memory.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);


	if (new_size > old_size)
		_memset(new_ptr + old_size, '\0', new_size - old_size);
	for (i = 0; i < old_size && i < new_size; i++)
		new_ptr[i] = *((char *)ptr + i);
	free(ptr);
	return (new_ptr);
}
