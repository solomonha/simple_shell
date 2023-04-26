#include"shell.h"
/**
 * _strtok - separates strings with delimiters
 * @string: string input
 * @delim: char that mark of the strings to be a part
 * Return: the created token's pointer
 */
char *_strtok(char *string, char *delim)
{
	int j;
	static char *str;
	char *strcpy;

	if (string != NULL)
		str = string;
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
				break;
		}
		if (delim[j] == '\0')
			break;
	}
	strcpy = str;
	if (*strcpy == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			{
				*str = '\0';
				str++;
				return (strcpy);
			}
		}
	}
	return (strcpy);
}
