#include <stdio.h>
#include <signal.h>

/**
 * get_sigint - Signal handler for SIGINT (Ctrl+C)
 * @sig: Signal number
 */
void get_sigint(int sig)
{
	printf("\n");
	fflush(stdout);
}
