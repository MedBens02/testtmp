#include "main.h"

/**
 * reverse_str - it reverses a str
 * @str: str
 * @len: len str
 */

void reverse_str(char *str, int len)
{
	char tmp;
	int start = 0, end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

/**
 * _strdup - duplicates a str
 * @str: str
 *
 * Return: duplicated str
 */
char *_strdup(const char *str)
{
	char *dup;
	int i, length = 0;

	if (str == NULL)
		return (NULL);
	while (str[length])
		length++;
	dup = malloc(sizeof(char) * (length + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		dup[i] = str[i];
	return (dup);
}
