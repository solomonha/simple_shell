#include "shell.h"

/**
 * execute - forks the process in to new proces(child)
 * @args: array of arguments
 * Return: -1 if it breaks, 0 if it doesn't
 */
int execute(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("");
			return (errno);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("");
		return (errno);
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
