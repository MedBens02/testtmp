#include "main.h"

/**
 * get_input - gets the next line of input from STDIN
 * Return: cmd
 */

char *get_input(void)
{
	char *input = NULL;
	size_t buff_len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		prompt();
	n = getline(&input, &buff_len, stdin);
	if (n == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}

/**
 * prompt - prints shell prompt
*/
void prompt(void)
{
	write(1, "$ ", 2);
}
