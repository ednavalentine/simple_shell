#include "main.h"
/**
 * get_env - searches for PATH in the environment variable
 * @name: string containing PATH
 * Return: Value of the string
 */
char *get_env(char *name)
{
	int cnt = 0;
	char *env_val;

	if (name == NULL)
	{
		return (NULL);
	}
	while (environ[cnt] != NULL)
	{
		if (_strcmp(environ[cnt], name) == 0)
		{
			env_val = _strchr(environ[cnt], '=');
			if (env_val == NULL)
			{
				return (NULL);
			}
			return (env_val + 1);
		}
		cnt++;
	}
	return (NULL);
}
