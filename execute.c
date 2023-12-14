#include "main.h"

/**
 * execute - execution of the commands
 *
 * @commands: the commands to execute
 * @av: args
 * @idx: index
 *
 * Return: exit code
 */

int execute(char **commands, char **av, int idx)
{
	pid_t pid;
	int status;
	char *cmd;


	cmd = get_path_command(commands[0]);
	if (cmd == NULL)
	{
		printerr(av[0], commands[0], idx);
		free_arr(commands);
		return (17);
	}

	pid = fork();

	if (pid == 0)
	{
		if (execve(cmd, commands, environ) == -1)
		{
			free(cmd), cmd = NULL;
			free_arr(commands);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free(cmd), cmd = NULL;
		free_arr(commands);
	}
	return (WEXITSTATUS(status));
}
