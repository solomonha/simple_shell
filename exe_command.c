#include "shell.h"

void exe_args(char **args)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		return;
	}
	else if (pid == 0)
	{
		if(execvp(args[0], args) < 0)
		{
			perror("Error");
		}
		exit(0);
	}
	else 
	{
		wait (NULL);
		return;
	}
}
