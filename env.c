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
/**
 * shell_setenv - changes enviromental variable to PATH
 * @d: struct
 * Return: If an error occurs -1.
 *
 */

int shell_setenv(data d)
{
	int i;
	int length = 0;
	int new_key = 1;

	if (d.tokens[1] == NULL || d.tokens[2] == NULL)
		return (0);
	if (d.tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(d.command);
		return (5);
	}

	if (d.env == NULL)
		return (0);
	_strlen(d.tokens[1]);
	for (i = 0; d.env[i]; i++)
	{
		if (_strcmp(d.tokens[1], d.env[i], length)
				&& d.env[i][length] == '=')
		{
			new_key = 0;
			free(d.env[i]);
			break;
		}
	}
}
d->env[i] = _strconc(_strcpy(key), "=");
s->env[i] = _strconc(d->env[i], d->tokens[2]);

if (new_key)
{
	d->env[i + 1] = NULL;
	}
return (0);
}



