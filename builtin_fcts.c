#include "main.h"

/**
 * exit_shell - Exits the shell.
 *
 * @commands: cmd str.
 * @av: arr of args
 * @status: exit status
 * @index: index
 */
void exit_shell(char **commands, char **av,  int *status, int idx)
{
	int exit_code = (*status);
	char *index, msg[] = ": exit: Illegal number: ";

	if (commands[1])
	{
		if (is_digit(commands[1]))
		{
			exit_code = _atoi(commands[1]);
		}
		else
		{
			index = _itoa(idx);
			write(2, av[0], _strlen(av[0]));
			write(2, ": ", 2);
			write(2, index, _strlen(index));
			write(2, msg, _strlen(msg));
			write(2, commands[1], _strlen(commands[1]));
			write(2, "\n", 1);
			free(index);
			free_arr(commands);
			(*status) = 2;
			return;
		}
	}
	free_arr(commands);
	exit(exit_code);
}

/**
 * print_env - Prints the environment
 *
 * @commands: arr of cmds
 * @status: exit status
 */
void print_environment(char **commands, int *status)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(1, environ[i], _strlen(environ[i]));
		_putchar('\n');
	}
	free_arr(commands);
	(*status) = 0;
}

/**
 * set_env - Sets a new environment variable or modifies an existing one.
 *
 * @commands: arr of cmds
 * @av: arr of args
 * @status: exit status
 * @idx: index
 */

void set_env(char **commands, char **av,  int *status, int idx)
{
	if (commands[1] && commands[2])
	{
		if (setenv(commands[1], commands[2], 1) != 0)
		{
			perror("setenv");
			*status = 1;
		}
	}
	else
	{
		write(2, av[0], _strlen(av[0]));
		write(2, ": ", 2);
		write(2, _itoa(idx), _strlen(_itoa(idx)));
		write(2, ": Usage: setenv VARIABLE VALUE\n", 30);
		*status = 1;
	}
	free_arr(commands);
}

/**
 * unset_env - Unsets (removes) an environment variable.
 *
 * @commands: arr of cmds
 * @av: arr of args
 * @status: exit status
 * @idx: index
 */
void unset_env(char **commands, char **av,  int *status, int idx)
{
	if (commands[1])
	{
		if (unsetenv(commands[1]) != 0)
		{
			perror("unsetenv");
			*status = 1;
		}
	}
	else
	{
		write(2, av[0], _strlen(av[0]));
		write(2, ": ", 2);
		write(2, _itoa(idx), _strlen(_itoa(idx)));
		write(2, ": Usage: unsetenv VARIABLE\n", 27);
		*status = 1;
	}
	free_arr(commands);
}
