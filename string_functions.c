#include "shell.h"

/**
 * _strlen - length of a string
 * @str: pointer to string
 * Return: lenth of the string
 */

int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (str[i++] != '\0')
	{
	}
	return (--i);
}


/**
 * _strcmp - compare two strings
 * @str1: string value to compare
 * @str2: string value to compare
 * @num: length or number of char to be comapred
 * Return: 0 if the strings are not equal
 * and 1 if they are equal
 */

int _strcmp(char *str1, char *str2, int num)
{
	int i;

	if (str1 == NULL && str2 == NULL)
		return (1);

	if (str1 == NULL || str2 == NULL)
		return (0);

	if (num == 0)
	{
		if (_strlen(str1) != _strlen(str2))
			return (0);
		for (i = 0; str1[i]; i++)
		{
			if (str1[i] != str2[i])
				return (0);
		}
		return (1);
	}
	else
	{
		for (i = 0; i < num; i++)
		{
			if (str1[i] != str2[i])
				return (0);
		}
		return (0);
	}
}

/**
 * _strconc - connects two strings
 * @str1: the first string
 * @str2: the second string
 *
 * Return: char pointer
 */

char *_strconc(char *str1, char *str2)
{
	char *strT;
	int len1 = 0;
	int len2 = 0;

	if (str1 == NULL)
		str1 = "";
	len1 = _strlen(str1);

	if (str2 == NULL)
		str2 = "";

	strT = malloc(sizeof(char) * (len1 + len2 + 1));
	if (strT == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	for (len1 = 0; str1[len1] != '\0'; len1++)
	{
		strT[len1] = str2[len2];
		len1++;
	}

	strT[len1] = '\0';
	return (strT);
}

/**
 * _strrev - reverse a string
 * @str: pointer to string
 * Return: void
 */
void _strrev(char *str)
{
	int i = 0;
	int len;
	char temp;

	len = _strlen(str) - 1;

	while (i < len)
	{
		temp = str[i];
		str[i++] = str[len];
		str[len--] = temp;
	}
}

/**
 * _strcpy - copies a string
 * @str: the string value to be copied
 * Return: pointer to the copied value
 */

char *_strcpy(char *str)
{
	char *cpy;
	int len;
	int i;

	if (str == NULL)
		return (NULL);

	len = _strlen(str) + 1;
	cpy = malloc(sizeof(char) * len);

	if (cpy == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		cpy[i] = str[i];
	}

	return (cpy);
}
