#include "shell.h"

/**
 * _memcpy - Copies a specified number of bytes from one memory area to another
 * @newptr: Pointer to the destination memory area
 * @ptr: Pointer to the source memory area
 * @size: Number of bytes to copy
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
    char *dest = (char *)newptr;
    const char *src = (const char *)ptr;

    for (unsigned int i = 0; i < size; i++)
        dest[i] = src[i];
}

/**
 * _realloc - Reallocates a memory block with a new size
 * @ptr: Pointer to the memory block to reallocate
 * @old_size: Old size of the memory block
 * @new_size: New size of the memory block
 *
 * Return: Pointer to the reallocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }

    void *new_ptr;

    if (ptr == NULL)
        new_ptr = malloc(new_size);
    else if (new_size <= old_size)
        return ptr;
    else
    {
        new_ptr = malloc(new_size);
        if (new_ptr != NULL)
        {
            _memcpy(new_ptr, ptr, old_size);
            free(ptr);
        }
    }

    return new_ptr;
}

/**
 * _reallocdp - Reallocates a dynamic array of pointers with a new size
 * @ptr: Pointer to the dynamic array of pointers to reallocate
 * @old_size: Old size of the dynamic array
 * @new_size: New size of the dynamic array
 *
 * Return: Pointer to the reallocated dynamic array of pointers
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }

    char **new_ptr = (char **)malloc(new_size * sizeof(char *));
    if (new_ptr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    unsigned int copy_size = old_size < new_size ? old_size : new_size;
    for (unsigned int i = 0; i < copy_size; i++)
        new_ptr[i] = ptr[i];

    free(ptr);

    return new_ptr;
}

