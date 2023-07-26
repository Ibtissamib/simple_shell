#include "shell.h"
/**
 * nbr_wrd- returns number of words in character chain
 * @str: pointer to char
 * @n: ssize_t
 *
 * Return: Integer
 */
int nbr_wrd(char *str, ssize_t n)
{
	int len = 0, j = 0;

	while (j < n)
	{
		if ((str[j] != ' ') && (str[j - 1] == ' ' || j == 0))
			len++;
		j++;
	}
	return (len);
}
