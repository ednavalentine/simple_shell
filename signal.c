#include "main.h"
/**
 * _sigint - handles CTRL-C signal
 * @sig_flag: flag used to determines signal
 * Return: nothing
 */
void _sigint(int sig_flag)
{
	char *input = NULL;

	(void) sig_flag;
	sig_flag = 1;
	write(STDOUT_FILENO, "\n", 1);
	free(input);
}
