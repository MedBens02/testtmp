#include "main.h"

/**
 * printerr - it prints error
 *
 * @name: name of shell
 * @command: command
 * @idx: index
 */

void printerr(char *name, char *command, int idx)
{
	char *index, msg[] = ": not found\n";

	index = _itoa(idx);
	write(2, name, _strlen(name));
	write(2, ": ", 2);
	write(2, index, _strlen(index));
	write(2, ": ", 2);
	write(2, command, _strlen(command));
	write(2, msg, _strlen(msg));
}
