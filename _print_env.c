#include "shell.h"
/**
 * _print_env-prints env
 *
 * Return: void
 */
void _print_env(void)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
		write(STDOUT_FILENO, str_concat(environ[i], "\n"), _strlen(environ[i]) + 1);
}

