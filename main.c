#include "main.h"
/**
 * main - entry point of the shell
 * @void: parameter to be used
 * Return: 0
 */
int main(void)
{
	char *input_prompt = "$ ";
	char *input = NULL;
	size_t n = 128;
	int num_chars;
	char **toks;
	char *file_path;
	pid_t child;
	int status = 0;
	struct stat buf;
	char *path_token;
	const char *delim = ":";
	size_t len_path;
	size_t len_toks;
	char *path;

	while (1)
	{
		write(STDOUT_FILENO, input_prompt, 3);
		num_chars = getline(&input, &n, stdin);
		if (num_chars == -1)
		{
			free(input);
			return (-1);
		}
		/*if (num_chars > 0 && input[num_chars - 1] == '\n')
		{
			input[num_chars - 1] = '\0';
		}*/
		toks = parse_data(input);
		child = fork();
		if (child == -1)
		{
			perror("./hsh");
			return (-1);
		}
		if (child == 0)
		{
			file_path = get_env("PATH");
			if (file_path == NULL)
			{
				return (-1);
			}
			path_token = strtok(file_path, delim);
			while (path_token != NULL)
			{
				len_path = _strlen(path_token);
				len_toks = _strlen(toks[0]);
				path = malloc(len_path + len_toks + 2);
				if (path == NULL)
				{
					perror("malloc");
					return (-1);
				}
				_strcpy(path, path_token);
				_strcat(path, "/");
				_strcat(path, toks[0]);
				_strcat(path, "\0");
				if (stat(path, &buf) == 0)
				{
					if (access(path, X_OK) == 0)
					{
						if (execve(path, toks, environ) == -1)
						{
							perror("execve");
							return (-1);
						}
					}
				}
				perror("access");
				perror("stat");
				free(path);
				path_token = strtok(NULL, delim);
			}
			exit(0);
		}
		else
		{
			wait(&status);
		}
		free_toks(toks);
	}
	free(input);
	return (0);
}
