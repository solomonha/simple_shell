#include "shell.h"

/**
 * read_line - Read the command from standard input
 * Return: A pointer that points to a string with the line content
 */
char *read_line(void)
{
	int bufsize = RL_BUFFER_SIZE;
	int line = 0;
	char *input = malloc(sizeof(char) * bufsize);
	int ch;

	if (!input)
	{
		dprintf(STDERR_FILENO, "ourshell: allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		/* Read a character */
		ch = getchar();
		/* If we hit EOF, replace it with a null character and return.*/
		if (ch == EOF || ch == '\n')
		{
			input[line] = '\0';
			return (input);
		}
		else
		{
			input[line] = ch;
		}
		line++;
		/* If we have exceeded the buffer, memory reallocation is required. */
		if (line >= bufsize)
		{
			bufsize += RL_BUFFER_SIZE;
			input = realloc(input, bufsize);
			if (!input)
			{
				dprintf(STDERR_FILENO, "ourshell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
