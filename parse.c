#include "shell.h"

/**
 * split_line - function to tokenize arguments or tokenize paths from PATH
 * @line: input string to tokenize/separate into arguments
 * Return: an array with multiple tokens
 */
char **split_line(char *line)
{
	int bufsize = TOK_BUFSIZE, index = 0;
	char **args = malloc(bufsize * sizeof(char *));
	char *token;

	if (!args)
	{
		dprintf(STDERR_FILENO, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		args[index] = token;
		indx++;
		if (index >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			args = realloc(args, bufsize * sizeof(char *));
			if (!args)
			{
				dprintf(STDERR_FILENO, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	args[index] = NULL;
	return (args);
}
