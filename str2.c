#include "shell.h"

/**
 * rev_string - Reverses a string in-place
 * @s: String to reverse
 */

void rev_string(char *s)
{
	if (s == NULL)
		return;

	int length = strlen(s);
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		char temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}
}
