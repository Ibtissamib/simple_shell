#include "shell.h"
/**
 * _exec_cmd- executes commands
 * @userinput: pointer to the userinput
 * @n: lenght of userinput
 * Return: void
 */
void _exec_cmd(char *userinput, ssize_t n)
{char **argv;
	ssize_t j = 0, i = 0, matrix_size = 0;
	char *b;
	int tr = 0;

	matrix_size = nbr_wrd(userinput, n);
	argv = (char **)malloc(sizeof(char *) * (matrix_size + 1));
	for (i = 0; (userinput[i] != ' ' && i < n); i++)
	{
		if (userinput[i] == '/')
		{	tr = 1;
			break; } }
	if (tr == 1)
	{	b = strtok(userinput, " ");
		if (j == matrix_size - 1)
			argv[j] = _decrem(b);
		else
			argv[j] = _strdup(b);
		b = strtok(NULL, " ");
		for (j = 1; j < matrix_size; j++)
		{
			if (j == matrix_size - 1)
				argv[j] = _decrem(b);
			else
				argv[j] = _strdup(b);
			b = strtok(NULL, " "); }
		argv[j] = NULL;
		if (execve(argv[0], argv, NULL) == -1)
		{write(STDOUT_FILENO, "sh: command: not found\n", 24);
			exit(EXIT_FAILURE); }
		if (argv != NULL)
		{
			for (j = 0; j <= matrix_size; j++)
				free(argv[j]);
			free(argv); }
		free(b); }
	else
		_path_handler(userinput, n); }
