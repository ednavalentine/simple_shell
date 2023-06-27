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
	char *file_path = NULL;
	char *filepath_cpy = NULL;
	char *path_token = NULL;
	const char *delim = ":";
	char *path = NULL;
	struct stat buf;

	if (cmd == NULL)
	{
		return (NULL);
	}
	file_path = getenv("PATH");
	filepath_cpy = strdup(file_path); /*use custom strdup*/
	if (file_path == NULL)
	{
		return (NULL);
	}
	path_token = strtok(filepath_cpy, delim);
	while (path_token != NULL)
	{
		path = malloc(_strlen(path_token) + _strlen(cmd) + 2);
		if (path == NULL)
		{
			return (NULL);
		}
		_strcpy(path, path_token);
		_strcat(path, "/");
		_strcat(path, cmd);
		if ((access(path, X_OK) == 0) && (stat(path, &buf) == 0))
		{
			return (path);
		}
		free(path);
		path_token = strtok(NULL, delim);
	}
	free(filepath_cpy);
	return (NULL);
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
	char *path = NULL;
	char *error = "Command not found: ";

	if (toks == NULL)
	{
		return;
	}
	path = find_path(toks[0]);
	if (path == NULL)
	{
		write(STDERR_FILENO, error, _strlen(error));
		write(STDERR_FILENO, toks[0], _strlen(toks[0]));
		write(STDERR_FILENO, "\n", 1);
		return;
	}
	child = fork();
	if (child < 0)
	{
		perror("child");
		exit(0);
	}
	else if (child == 0)
	{
		if (execve(path, toks, environ) == -1)
		{
			perror("execve");
			exit(0);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(0);
		}
		if (WIFEXITED(status))
		{
			WEXITSTATUS(status);
		}
		else if (WIFSIGNALED(status))
		{
			WTERMSIG(status);
		}
		else
		{
			perror("fork");
		}
	}
	free(path);
}
