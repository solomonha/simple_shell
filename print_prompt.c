#include "shell.h"

/**
 * print_prompt - command line interpreter
 * Return: void
 */
void print_prompt(void)
{
	char *line;
	char **args;
	int status = -1;
	size_t length = 0;

	do {
		printf("ourshell$ ");
		line = _getline();
		args = _strtok(line);
		status = getline(args, &length, stdin);
		free(line);
		free(args);
		if (status >= 1)
		{
			exit(status);
		}
	} while (status == -1);

}
