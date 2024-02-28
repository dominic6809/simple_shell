#include <stdlib.h>
#include <string.h>

/**
 * get_path - Retrieves the system's PATH environment variable.
 * Return: A pointer to a string representing the current value of the PATH
 *        environment variable,or NULL if an error occurs.
 */

char *get_path()
{
	return (getenv("PATH"));
}

/**
 * set_path - Sets the system's PATH environment variable to a specified value.
 * @new_path: The new value be set for PATH environment variable.
 * Return: 0 if the PATH variable is successfully updated,
 *        or -1 if an error occurs.
 */

int set_path(const char *new_path)
{
	return (setenv("PATH", new_path, 1));
}

/**
 * add_to_path - Adds a directory to the system's PATH environment variable.
 * @dir: The directory path to be added.
 * Return: 0 if the directory is successfully added to the PATH,
 *         or -1 if an error occurs after successful compilation
 */

int add_to_path(const char *dir)
{
	/* Get the current PATH */

	char *path = get_path();
	char *new_path;

	if (path == NULL)
	{
		return (-1);
	}

	/* Allocate memory for the new PATH */
	/* +2 for the colon and the null terminator */

	new_path = malloc(strlen(path) + strlen(dir) + 2);

	if (new_path == NULL)
	{
		return (-1);
	}

	/* Create the new PATH */

	strcpy(new_path, path);
	strcat(new_path, ":");
	strcat(new_path, dir);


	/* Set the new PATH */

	if (set_path(new_path) == -1)
	{
		free(new_path);
		return (-1);
	}


	/* Free the memory for the new PATH */

	free(new_path);
	return (0);
}
