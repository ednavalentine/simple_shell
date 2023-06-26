#include "main.h"
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

    /* Added custom function to avoid splitting strings between quotes */
	str_token = strmbtok(str, delim);

	while (str_token != NULL)
	{
        len = _strlen(str_token);
        toks = (char **) realloc(toks, len * sizeof **toks); // Looks a bit neat
		toks[count] = malloc(len + 1);

		if (toks[count] == NULL)
		{
			free_toks(toks);
			return (NULL);
		}

		_strcpy(toks[count], str_token);
		str_token = strmbtok(NULL, delim);

		count++;
	}

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
