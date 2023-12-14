#include "main.h"

/**
 * get_path_command - adds path to a command
 * @command: input command
 *
 * Return: path + command
 */


char *get_path_command(char *command)
{
	char *path, *elt, *path_command;
	struct stat st;
	int i;

	while (command[i] != '\0')
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
		i++;
	}
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	elt = strtok(path, ":");
	while (elt)
	{
		path_command = malloc(_strlen(elt) + _strlen(command) + 2);
		if (path_command != NULL)
		{
			_strcpy(path_command, elt);
			_strcat(path_command, "/");
			_strcat(path_command, command);
			if (stat(path_command, &st) == 0)
			{
				free(path);
				return (path_command);
			}
			free(path_command), path_command = NULL;
			elt = strtok(NULL, ":");
		}
	}
	free(path);
	return (NULL);
}
