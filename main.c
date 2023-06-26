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
	/*char *path = NULL;*/

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
		if (num_chars > 0 && input[num_chars - 1] == '\n') /*returned this since i fixed _strlen*/
		{
			input[num_chars - 1] = '\0';
		}
		toks = parse_data(input);
		if (toks != NULL)
		{
			exec_input(toks);
		}
		/*free(path); so this does not cause issues na gcc and valgrind when its not present in the code*/
		free_toks(toks);
		/*n = 0;*/
	}
	free(input);
	return (0);
}
