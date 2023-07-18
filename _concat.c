#include "shell.h"
/**
 * str_concat-  concatenates two strings.
 * @s1: pointer to char
 * @s2: pointer to char
 *
 * Return: pointer to char
 */
char *str_concat(char *s1, char *s2)
{
	char *s;
	int i = 0, j = 0;

	if (s1 == NULL)
		s1 = "\0";
	if (s2 == NULL)
		s2 = "\0";
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	s = malloc((sizeof(char) * (i + j)) + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}
