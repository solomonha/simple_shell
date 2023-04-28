#include "shell.h"

/**
 * main - function that checks if our shell is called
 * Return: 0 on success
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		print_prompt();
	}
	return (0);
}
