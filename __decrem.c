#include "shell.h"
/**
 * _decrem-delete the last character of a character chain
 * @b: pointer to char
 *
 * Return: pointer to char
 */
char *_decrem(char *b)
{
	char *cmd;
	int i = 0;

	cmd = (char *)malloc(sizeof(char) * _strlen(b));
	for (i = 0; i < (_strlen(b) - 1); i++)
		cmd[i] = b[i];
	cmd[i] = '\0';
	return (cmd);
}
