#include "main.h"

/**
 * custom_hello - Entry point of the program
 * Return: 0 when successful
 */

int custom_hello(void)
{
	const char message[] = "Hello, world!\n";

	write(1, message, sizeof(message) - 1);
	return (0);
}
