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
	size_t n = 0;
	int num_chars;
	char **toks;
	char *argv[] = {"/usr/bin/pwd", (char *)0};
	char *envp[] = {"PATH=/bin", (char *)0};
	pid_t child;
	int status = 0;

	while (1)
	{
		write(STDOUT_FILENO, input_prompt, 3);
		num_chars = getline(&input, &n, stdin);
		if (num_chars == -1)
		{
			free(input);
			return (-1);
		}
		toks = parse_data(input);
		child = fork();
		if (child == -1)
		{
			perror("./sh");
			return (-1);
		}
		if (child == 0)
		{
			if (access(argv[0], X_OK) == -1)
			{
				return (-1);
			}
			if (execve(argv[0], argv, envp) == -1)
			{
				perror("./sh");
				return (-1);
			}
		}
		else
		{
			wait(&status);
		}
		free_toks(toks);
		/*exit(status);*/
	}
	free(input);
	return (0);
}
