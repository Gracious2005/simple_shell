#include "shell.h"

/**
 * _myenv - prints current environment
 * @info: Structure that holds arguments
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - obtain value of environment variable
 * @info: Structure that holds arguments
 * @name: environment name
 *
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize or modify variable
 * @info: Structure that holds arguments
 *  Return: 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Take out environment variable
 * @info: Structure that holds argument
 * Return: 0
 */
int _myunsetenv(info_t *info)
{
	int e;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (e = 1; e <= info->argc; e++)
		_unsetenv(info, info->argv[e]);

	return (0);
}

/**
 * populate_env_list - occupy environment linked list
 * @info: Structure that carries arguments.
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t e;

	for (e = 0; environ[e]; e++)
		add_node_end(&node, environ[e], 0);
	info->env = node;
	return (0);
}
