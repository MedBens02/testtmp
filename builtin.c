#include "main.h"

/**
 * is_builtin - Checks if a command is a built-in shell.
 *
 * @command: cmd str.
 *
 * Return: 1 if built-in, 0 otherwise.
 */
int is_builtin(char *command)
{
	char *builtins_arr[] = BUILTIN;
	int i;

	for (i = 0; builtins_arr[i]; i++)
	{
		if (_strcmp(command, builtins_arr[i]) == 0)
		return (1);
	}
	return (0);
}

/**
 * find_builtin - Executes built-in commands.
 *
 * @commands: arr of strs
 * @av: arr of args
 * @status: exit status
 * @index: command indx
 */
void find_builtin(char **commands, char **av, int *status, int index)
{
	if (_strcmp(commands[0], "exit") == 0)
	exit_shell(commands, av, status, index);

	else if (_strcmp(commands[0], "env") == 0)
	print_environment(commands, status);

	else if (_strcmp(commands[0], "setenv") == 0)
	set_env(commands, av, status, index);

	else if (_strcmp(commands[0], "unsetenv") == 0)
	unset_env(commands, av, status, index);
}
