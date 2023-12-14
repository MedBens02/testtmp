#include "main.h"

/**
 * _strcat - concatenates two strings.
 *
 * @dest: result
 * @src: source
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	char *end = dest;

	while (*end != '\0')
		end++;
	while (*src != '\0')
	{
		*end = *src;
		end++;
		src++;
	}

	*end = '\0';
	return (dest);
}

/**
 * _strlen - returns the length of a string.
 *
 * @s: setring
 *
 * Return: string length
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; *s != '\0'; s++)
		++len;

	return (len);
}

/**
 * _strcmp - compares two strings.
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: comparison result
 */
int _strcmp(char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * *_strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 *
 * @dest: buffer
 * @src: input
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *pt_to_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (pt_to_dest);
}
