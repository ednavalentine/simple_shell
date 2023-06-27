#include "main.h"
/**
 * _strdup - duplicates a string
 * @str: char pointer
 * Return: pointer to duplicated string, or NULL
 */
char *_strdup(char *str)
{
	int i;
	char *duplicate;

	if (str == NULL)
	{
		return (NULL);
	}
	duplicate = malloc(_strlen(str) + 1);
	if (duplicate != NULL)
	{
		for (i = 0; i < _strlen(str); i++)
		{
			duplicate[i] = str[i];
		}
		duplicate[i] = '\0';
		return (duplicate);
	}
	else
	{
		free(duplicate);
		return (NULL);
	}
}
