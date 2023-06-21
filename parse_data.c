#include "main.h"
/**
 * _strlen - returns length of string
 * @s: char pointer
 * Return: len
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i))
	{
		i++;
	}
	return (i);
}
/**
 * _strcpy - copies the string
 * @dest: destination pointer
 * @src: source pointer
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int j;

	while (*(src + i) != '\0')
	{
		i++;
	}
	for (j = 0; j < i; j++)
	{
		dest[j] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * parse_data - parsing data from getline
 * @str: user input
 * Return: tokenised value
 */
char **parse_data(char *str)
{
	const char *delim = " ";
	char *str_token = NULL;
	char **toks = NULL;
	size_t count = 0;
	size_t len = 0;

	toks = malloc(sizeof(char *) * (count + 2));
	if (toks == NULL)
	{
		return (NULL);
	}
	str_token = strtok(str, delim);
	len = _strlen(str_token);
	while (str_token != NULL)
	{
		toks[count] = malloc(len + 1);
		if (toks[count] == NULL)
		{
			/*add free for both array element and array*/
			return (NULL);
		}
		_strcpy(toks[count], str_token);
		str_token = strtok(NULL, delim);
		if (str_token != NULL)
		{
			len = _strlen(str_token);
		}
		count++;
	}
	toks[count] = NULL;
	return (toks);
}
/**
 * free_toks - frees toks variable
 * @toks: pointer to char pointer
 * Return: nothing
 */
void free_toks(char **toks)
{
	int i = 0;

	while (toks[i] != NULL)
	{
		free(toks[i]);
		i++;
	}
	free(toks);
}
