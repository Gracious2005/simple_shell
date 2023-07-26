#include "shell.h"

/**
 * _eputs - prints input string
 * @str: string
 *
 * Return: NULL
 */
void _eputs(char *str)
{
	int e = 0;

	if (!str)
		return;
	while (str[e] != '\0')
	{
		_eputchar(str[e]);
		e++;
	}
}

/**
 * _eputchar - writes c to stderr
 * @c: char
 *
 * Return: On success 1.
 * -1 is returned on failure and errno is set
 */
int _eputchar(char c)
{
	static int e;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || e >= WRITE_BUF_SIZE)
	{
		write(2, buf, e);
		e = 0;
	}
	if (c != BUF_FLUSH)
		buf[e++] = c;
	return (1);
}

/**
 * _putfd - writes c to fd
 * @c: character
 * @fd: filedescriptor
 *
 * Return: On success 1.
 * -1 is returned on failure and errno is set appropriately
 */
int _putfd(char c, int fd)
{
	static int e;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || e >= WRITE_BUF_SIZE)
	{
		write(fd, buf, e);
		e = 0;
	}
	if (c != BUF_FLUSH)
		buf[e++] = c;
	return (1);
}

/**
 * _putsfd - print input string
 * @str: string
 * @fd: filedescriptor
 *
 * Return: no of chars
 */
int _putsfd(char *str, int fd)
{
	int e = 0;

	if (!str)
		return (0);
	while (*str)
	{
		e += _putfd(*str++, fd);
	}
	return (e);
}
