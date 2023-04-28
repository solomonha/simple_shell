#include "shell.h"

size_t exe_args(char *line, char **args)
{
	pid_t pid = fork();
	int status;
	char **envp = environ;

	if (pid == -1)
	{
		return (0);
	}
	else if (pid == 0)
	{
		if(execve(line, args, envp)  < 0)
		{
		perror("Error");
		}
		exit(0);
	}
	else 
	{
		wait (&status);
		return (0);
	}
}
