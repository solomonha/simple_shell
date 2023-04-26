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

	do {
		printf("ourshell$ ");
		line = _getline();
		args = _strtok(line);
		status = execute_commands(args);
		free(line);
		free(args);
		if (status >= 1)
		{
			exit(status);
		}
	} while (status == -1);

}


