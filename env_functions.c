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
/**
 * find_path - get the path/location of the executable file
 * @cmd: char ptr
 * Return: path
 */
char *find_path(char *cmd)
{
	char *file_path;
	char *path_token;
	const char *delim = ":";
	char *path;
	size_t len_path;
	size_t len_toks;

	file_path = get_env("PATH");
	if (file_path == NULL)
	{
		return (NULL);
	}
	path_token = strtok(file_path, delim);
	while (path_token != NULL)
	{
		len_path = _strlen(path_token);
		len_toks = _strlen(cmd);
		path = malloc(len_path + len_toks + 2);
		if (path == NULL)
		{
			return (NULL);
		}
		_strcpy(path, path_token);
		_strcat(path, "/");
		_strcat(path, cmd);
		path_token = strtok(NULL, delim);
	}
	return (path);
}
/**
 * exec_input - replaces child process with a new program
 * @toks: pointer to char pointer
 * Return: nothing
 */
void exec_input(char **toks)
{
	pid_t child;
	int status = 0;
	char *file_path;

	file_path = find_path(toks[0]);
	child = fork();
	if (child == -1)
	{
		perror("./hsh");
		exit(1);
	}
	if (child == 0)
	{
		if (execve(file_path, toks, environ) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
		wait(&status); /*waitpid(child, &status, 0);*/
	}
	free(file_path);
}
