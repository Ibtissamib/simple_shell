#include "shell.h"
/**
 * _strlen- returns the length of a string
 * @s: pointers on string
 *
 * Return: Integer
 */
ssize_t _strlen(char *s)
{
	ssize_t length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
