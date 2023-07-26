#include "shell.h"

/**
 * interactive - checks if shell is interactive
 * @info: This is the structural address
 *
 * Return: 0 if shell is not interactive, 1 if it is
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if char is delimeter
 * @c: char
 * @delim: delimeter string
 * Return: 0 if false, 1 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - deterines  an alphabetic character
 * @c: char
 * Return: 0 if c is not alphabetic
 * 1 if character is alphabetic
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts string to integer
 * @s: string
 * Return: converted number otherwise 0
 */

int _atoi(char *s)
{
	int e, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (e = 0; s[e] != '\0' && flag != 2; e++)
	{
		if (s[e] == '-')
			sign *= -1;

		if (s[e] >= '0' && s[e] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[e] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}


