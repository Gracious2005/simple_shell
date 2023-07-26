#include "shell.h"

/**
 * _erratoi - converts string to integer
 * @s: string
 * Return: converted number otherwise 0
 * -1 on error
 */
int _erratoi(char *s)
{
	int e = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (e = 0;  s[e] != '\0'; e++)
	{
		if (s[e] >= '0' && s[e] <= '9')
		{
			result *= 10;
			result += (s[e] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints error message
 * @info: parameter and info structure
 * @estr: string that contains error
 * Return: converted number otherwise 0
 * -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints in base 10
 * @input: input
 * @fd: filedescriptor to write into
 *
 * Return: no of characters
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int e, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (e = 1000000000; e > 1; e /= 10)
	{
		if (_abs_ / e)
		{
			__putchar('0' + current / e);
			count++;
		}
		current %= e;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - convert function
 * @num: number or no
 * @base: base
 * @flags: flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces '#' with '\0'
 * @buf: address
 *
 * Return: 0
 */
void remove_comments(char *buf)
{
	int e;

	for (e = 0; buf[e] != '\0'; e++)
		if (buf[e] == '#' && (!e || buf[e - 1] == ' '))
		{
			buf[e] = '\0';
			break;
		}
}
