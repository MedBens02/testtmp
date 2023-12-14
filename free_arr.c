#include "main.h"

/**
 * free_arr - frees an arr of strs
 *
 * @arr: arr of strs
*/
void free_arr(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr), arr = NULL;
}
