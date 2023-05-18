#include <stdio.h>

/**
 * aux_help - Display general help information
 */
void aux_help(void)
{
	printf("Shell Help\n");
	printf("Available commands:\n");
	printf("alias\n");
	printf("cd\n");
}

/**
 * aux_help_alias - Display help information for the "alias" command
 */
void aux_help_alias(void)
{
	printf("alias: alias [NAME[='VALUE'] ...]\n");
	printf("    Define or display aliases.\n");
}
/**
 * aux_help_cd - Display help information for the "cd" command
 */
void aux_help_cd(void)
{
	printf("cd: cd [DIRECTORY]\n");
	printf("    Change the current working directory.\n");
}
