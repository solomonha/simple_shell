#include "shell.h"
/**
 * checker - checkes ans split if there
 * is any && || operators
 * @i: index in the commands
 * @array_operators: array of logical operators
 * @array_command: set of commands stored in
 * an form of array
 * Return: index of the last command
 */
int checker(char *array_command[], int i, char array_operators[])
{
	char *temp = NULL;
	int j;

	for (j = 0; array_command[i] != NULL && array_command[i][j]; j++)
	{
		if (array_command[i][j] == '&' && array_command[i][j + 1] == '&')
		{
			temp = array_command[i];
			array_command[i][j] = '\0';
			array_command[i] = _strdup(array_command[i]);
			array_command[i + 1] = _strdup(temp + j + 2);
			i++;
			array_operators[i] = '&';
			free(temp);
			j = 0;
		}
		if (array_command[i][j] == '|' && array_command[i][j + i] == '|')
		{
			temp = array_command[i];
			array_command[i][j] = '\0';
			array_command[i] = _strdup(array_command[i]);
			array_command[i + 1] = _strdup(temp + j + 2);
			i++;
			array_operators[i] = '|';
			free(temp);
			j = 0;
		}
	}
	return (i);
}
/**
 * _getline - the same function
 * @d: structure data
 * Return: reading counting bytes
 */
int _getline(data *d)
{
	char buffer[RL_BUFFER_SIZE] = { '\0'};
	static char *array_command[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t byte_read, i = 0;

	if (!array_command[0] || (array_operators[0] == '&' && errno != 0)
			|| (array_operators[0] == '|' && errno == 0))
	{
		for (i = 0; array_command[i]; i++)
		{
			free(array_command[i]);
			array_command[i] = NULL;
		}
		byte_read = read(d->file_descriptor, &buffer, RL_BUFFER_SIZE - 1);
		if (byte_read == 0)
			return (-1);
		i = 0;

		do {
			array_command[i] = _strdup(strtok(i ? NULL : buffer, "\n;"));
			i = checker(array_command, i, array_operators);
		} while (array_command[i++]);
	}
	d->input = array_command[0];
	for (i = 0; array_command[i]; i++
			{
			array_command[i] = array_command[i + 1];
			array_operators[i] = array_operators[i + 1];
			}
			return (_strlen(d->input));
			}
