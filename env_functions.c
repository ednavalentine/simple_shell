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
	struct stat buf;
	int path_found = 0; /* flag check to see if executable is found */

	if (cmd == NULL)
	{
		return (NULL);
	}
	file_path = getenv("PATH");
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
		_strcat(path, "\0");
		if ((access(path, F_OK) == 0) && (access(path, X_OK) == 0) &&
				(stat(path, &buf) == 0) && S_ISREG(buf.st_mode))
		{
			path_found = 1;
			break;
		}
		free(path);
		path_token = strtok(NULL, delim);
	}
	if (path_found)
	{
		return (path);
	}
	else
	{
		return (NULL);
	}
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
	char *error = "No such file or directory: ";

	path = find_path(toks[0]);
	if (path == NULL)
	{
		write(STDERR_FILENO, error, _strlen(error));
		write(STDERR_FILENO, toks[0], _strlen(toks[0]));
		write(STDERR_FILENO, "\n", 1);
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
			free(path);
			perror("execve");
			exit(0);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(1);
		}
		/*if (WIFEXITED(status))
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
		}*/
	}
	free(path);
}
