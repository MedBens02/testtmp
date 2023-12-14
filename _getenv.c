#include "main.h"

/**
 * _getenv - get environement
 *
 * @name: name of the key
 *
 * Return: keys's value
*/

char *_getenv(const char *name)
{
	int i;
	char *key, *copy, *value, *env;

	while (environ[i])
	{
		copy = _strdup(environ[i]);
		key = strtok(copy, "=");
		if (_strcmp(key, name) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(copy);
			return (env);
		}
		free(copy), copy = NULL;
		i++;
	}
	return (NULL);
}
