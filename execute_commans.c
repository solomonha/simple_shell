#include "shell.h"

/**
 * execute_commands - map if command is a builtin or a process
 * @args: command and its flags
 * Return: command and its flags
 */
int execute_commands(char **args)
{
	char *builtin_command_list[] = {
		"cd",
		"env",
		"help",
		"exit"};
	int (*builtin_command[])(char **) = {
		&our_cd,
		&our_env,
		&our_help,
		&our_exit
	};
	int i = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (; i < sizeof(builtin_command_list) / sizeof(char *); i++)
	{
		if (strcmp(args[0], builtin_command_list[i]) == 0)
		{
			return ((*builtin_command[i])(args));
		}
	}
	return (execute(args));
}



