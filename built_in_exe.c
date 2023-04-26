#include"shell.h"
/**
 * builtin_exe - executes the built in function
 * @tokens: the arguments being passed
 * Return: int value
 */
int builtin_exe(char **tokens)
{
	int status;
	unsigned int length, num, i = 0, j;

	builtin builtins[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};

	if (tokens[0] == NULL)
		return (1);
	length = _strlen(tokens[0]);
	while (builtins[i].name != NULL)
		i++;
	num = i;
	for (j = 0; j < num; j++)
	{
		if (_strcmp(tokens[0], builtins[j].name, length) == 0)
		{
			status = (builtins[j].f)();
			return (status);
		}
	}
	return (1);
}
