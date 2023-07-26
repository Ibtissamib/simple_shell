#include "shell.h"
/**
 * _path_handler-handles path
 * @userinput: pointer to char
 * @n: ssize_t
 * Return: void
 */
void _path_handler(char *userinput, ssize_t n)
{	ssize_t j = 0, matrix_size = 0, finder_path = 0;
	char **argv, *b, *cmd,  *path_cmd, *s;

	matrix_size = nbr_wrd(userinput, n);
	argv = (char **)malloc(sizeof(char *) * (matrix_size + 1));
	b = strtok(userinput, " ");
	if (j == matrix_size - 1)
		cmd = _decrem(b);
	else
		cmd = _strdup(b);
	b = strtok(NULL, " ");
	for (j = 1; j < matrix_size; j++)
	{
		if (j == matrix_size - 1)
			argv[j] = _decrem(b);
		else
			argv[j] = _strdup(b);
		b = strtok(NULL, " "); }
	s = str_concat(str_concat(strtok(_getenv("PATH"), ":"), "/"), cmd);
	while (path_cmd != NULL)
	{
		if (access(s, F_OK) == 0)
		{	finder_path = 1;
			break; }
		s = str_concat(str_concat(path_cmd = strtok(NULL, ":"), "/"), cmd); }
	if (finder_path == 1)
		argv[0] = _strdup(s);
	else
		argv[0] = _strdup("no");
	argv[j] = NULL;
	if (execve(argv[0], argv, NULL) == -1)
	{	write(STDOUT_FILENO, "sh: command: not found\n", 24);
		exit(EXIT_FAILURE); }
	if (argv != NULL)
	{
		for (j = 0; j <= matrix_size; j++)
			free(argv[j]);
		free(argv); }
	free(b);
	free(cmd);
	free(path_cmd);
	free(s); }
