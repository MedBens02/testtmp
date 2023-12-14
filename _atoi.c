#include "main.h"

/**
 * _atoi - convert a string to an integer.
 *
 * @s: str input
 *
 * Return: n
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int n = 0;

	do {
		if (*s == '-')
			sign *= -1;

		else if (*s >= '0' && *s <= '9')
			n = n * 10 + (*s - '0');
		else if (n > 0)
			break;
	} while (*s++);
	n = n * sign;

	return (n);
}

/**
 * is_digit - checks if a number is positive
 *
 * @str: arr of strs
 *
 * Return: 1 if positive, otherwise 0
 */

int is_digit(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}


/**
 * _itoa - convert int to str
 *
 * @n: int
 *
 * Return: str
 */

char *_itoa(int n)
{
	char buffer[30];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_str(buffer, i);
	return (_strdup(buffer));
}
