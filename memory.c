#include "shell.h"

/**
 * bfree - frees pointer
 * @ptr: address of the pointer
 *
 * Return: 1 if it becomes free, if not 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
