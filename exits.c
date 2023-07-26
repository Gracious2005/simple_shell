#include "shell.h"

/**
 **_strncpy - copies string
 *@dest: destination
 *@src: source string
 *@n: no of char to be copy
 *Return: concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int e, f;
	char *s = dest;

	e = 0;
	while (src[e] != '\0' && e < n - 1)
	{
		dest[e] = src[e];
		e++;
	}
	if (e < n)
	{
		f = e;
		while (f < n)
		{
			dest[f] = '\0';
			f++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: 1st string
 *@src: 2nd string
 *@n: no of bytes to be used
 *Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int e, f;
	char *s = dest;

	e = 0;
	f = 0;
	while (dest[e] != '\0')
		e++;
	while (src[f] != '\0' && f < n)
	{
		dest[e] = src[f];
		e++;
		f++;
	}
	if (f < n)
		dest[e] = '\0';
	return (s);
}

/**
 **_strchr - locates char in string
 *@s: string to parse
 *@c: character to find
 *Return: pointer to memory area
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
