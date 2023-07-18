#include "shell.h"
/**
 * nbr_wrd- returns number of words in character chain
 * @str: pointer to char
 * @nlines: ssize_t
 *
 * Return: Integer
 */
int nbr_wrd(char *str, ssize_t nlines)
{
	int len = 0, j = 0;

	while (j < nlines)
	{
		if ((str[j] != ' ')  && ((str[j - 1] == ' ') || (j == 0)))
			len++;
		j++;
	}
	return (len);
}
