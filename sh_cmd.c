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
/**
 * _path_handler-handles path
 * @userinput: pointer to char
 * @nlines: ssize_t
 * Return: void
 */
void _path_handler(char *userinput, ssize_t nlines)
{	ssize_t j = 0, matrix_size = 0, finder_path = 0;
	char **argv, *b, *cmd,  *path_cmd, *s;

	matrix_size = nbr_wrd(userinput, nlines);
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

/**
 * sh_cmd- executes commands
 * @userinput: pointer to the userinput
 * @nlines: lenght of userinput
 * Return: void
 */
void sh_cmd(char *userinput, ssize_t nlines)
{char **argv;
	ssize_t j = 0, i = 0, matrix_size = 0;
	char *b;
	int tr = 0;

	matrix_size = nbr_wrd(userinput, nlines);
	argv = (char **)malloc(sizeof(char *) * (matrix_size + 1));
	for (i = 0; (userinput[i] != ' ' && i < nlines); i++)
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
		_path_handler(userinput, nlines); }
