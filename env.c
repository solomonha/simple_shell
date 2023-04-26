#include "shell.h"
/**
 * shell_env - separates strings with delimiters
 * Return: nothing
 */

int shell_env(void)
{
	unsigned int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
