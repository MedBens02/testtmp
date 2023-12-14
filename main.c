#include "main.h"

/**
 * main - Entry point
 * @ac: number of args
 * @av: args
 *
 * Return: 0 on success
*/

int main(int ac, char **av)
{
	char *buff = NULL, **commands = NULL;
	int status = 0, index = 0;
	(void)ac;

	while (1)
	{
		buff = get_input();
		if (buff == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			return (status);
		}

		index++;
		commands = seperate_commands(buff);
		if (commands == NULL)
			continue;

		if (is_builtin(commands[0]))
			find_builtin(commands, av, &status, index);
		else
			status = execute(commands, av, index);
	}
	free(buff);
	return (0);
}
