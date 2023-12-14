#include "main.h"


/**
 * _puts -  prints a string, followed by a new line, to stdout.
 *
 * @str: string input
 *
 * Return: Nothing
 */

void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str +  0);
		str++;
	}
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
