#include "main.h"

/**
 * seperate_commands - separate commands and args
 *
 * @buff: input buff
 *
 * Return: commands separated
 */


char **seperate_commands(char *buff)
{
	char **commands = NULL;
	char *elt = NULL, *copy = NULL;
	int i = 0, nbr_args = 0;

	if (buff == NULL)
		return (NULL);

	copy = _strdup(buff);
	elt = strtok(copy, " \t\n");
	if (elt == NULL)
	{
		free(copy), copy = NULL;
		free(buff), buff = NULL;
		return (NULL);
	}
	while (elt != NULL)
	{
		nbr_args++;
		elt = strtok(NULL, " \t\n");
	}
	free(copy), copy = NULL;
	commands = malloc(sizeof(char *) * (nbr_args + 1));
	if (commands == NULL)
	{
		free(buff), buff = NULL;
		return (NULL);
	}
	elt = strtok(buff, " \t\n");
	while (elt)
	{
		commands[i] = _strdup(elt);
		i++;
		elt = strtok(NULL, " \t\n");
	}
	commands[i] = NULL;
	free(buff), buff = NULL;

	return (commands);
}
