#include "shell.h"
/**
 * _strdup- returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter
 * @str: pointer to char
 *
 * Return: pointer to char
 */
char *_strdup(char *str)
{
	char *p;
	int i = 0;

	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	p = malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		p[i] = str[i];
		i++;
	}
	return (p);
}
