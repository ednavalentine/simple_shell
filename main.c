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
	int sig_flag = 0;

	signal(SIGINT, _sigint);

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, input_prompt, _strlen(input_prompt));
		}
		num_chars = getline(&input, &n, stdin);
		if (num_chars == -1)
		{
			free(input);
			exit(0);
		}
		if (input[num_chars - 1] == '\n')
		{
			input[num_chars - 1] = '\0';
		}
		if (sig_flag)
		{
			free(input);
			exit(0);
		}
		toks = parse_data(input);
		if (toks != NULL)
		{
			exec_input(toks);
		}
		free_toks(toks);
	}
	free(input);
	return (0);
}
