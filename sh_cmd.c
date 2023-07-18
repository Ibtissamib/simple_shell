#include "shell.h"
/**
 * _path_handler-handles path
 * @userinput: pointer to char
 * @nlines: ssize_t
 * Return: void
 */
void _path_handler(char *userinput, ssize_t nlines)
{
	ssize_t j = 0, i = 0, matrix_size = 0;
	char **argv, *b, *cmd,  *path_cmd, *path, *s, *s_slash;
	int finder_path = 0;

	matrix_size = nbr_wrd(userinput, nlines);
	argv = (char **)malloc(sizeof(char *) * (matrix_size + 1));
	b = strtok(userinput, " ");
	if (j == matrix_size - 1)
	{
		cmd = (char *)malloc(sizeof(char) * _strlen(b));
		for (i = 0; i < (_strlen(b) - 1); i++)
			cmd[i] = b[i];
		cmd[i] = '\0';
	}
	else
		cmd = _strdup(b);
	b = strtok(NULL, " ");
	for (j = 1; j < matrix_size; j++)
	
	{
		if (j == matrix_size - 1)
		{
			argv[j] = (char *)malloc(sizeof(char) * _strlen(b));
			for (i = 0; i < (_strlen(b) - 1); i++)
				argv[j][i] = b[i];
			argv[j][i] = '\0';
		}
		else
			argv[j] = _strdup(b);
		b = strtok(NULL, " ");
	}
	path = _getenv("PATH");
	path_cmd = strtok(path, ":");
	s_slash = str_concat(path_cmd, "/");
	s = str_concat(s_slash, cmd);
	while (path_cmd != NULL)
	{
		if (access(s, F_OK) == 0)
		{	finder_path = 1;
			break;
		}
		path_cmd = strtok(NULL, ":");
		s_slash = str_concat(path_cmd, "/");
		s = str_concat(s_slash, cmd);
	}
	if (finder_path == 1)
		argv[0] = _strdup(s);
	else
		argv[0] = _strdup("no");

	argv[j] = NULL;
	if (execve(argv[0], argv, NULL) == -1)
	{
		write(STDOUT_FILENO, "sh: command: not found\n", 24);
		exit(EXIT_FAILURE);
	}
	if (argv != NULL)
	{
		for (j = 0; j <= matrix_size; j++)
			free(argv[j]);
		free(argv);
	}
	free(b);
	free(cmd);
	free(path_cmd);
	free(path);
	free(s);
	free(s_slash);
}

/**
 * sh_cmd- executes commands
 * @userinput: pointer to the userinput
 * @nlines: lenght of userinput
 * Return: void
 */
void sh_cmd(char *userinput, ssize_t nlines)
{char **argv;
	ssize_t j = 0, i = 0;
	ssize_t matrix_size = 0;
	char *b;
	int tr = 0;

	matrix_size = nbr_wrd(userinput, nlines);
	argv = (char **)malloc(sizeof(char *) * (matrix_size + 1));
	for (i = 0; (userinput[i] != ' ' && i < nlines); i++)
	{
		if (userinput[i] == '/')
		{
			tr = 1;
			break;
		}
	}
	if (tr == 1)
	{
		b = strtok(userinput, " ");
		if (j == matrix_size - 1)
		{
			argv[j] = (char *)malloc(sizeof(char) * _strlen(b));
			for (i = 0; i < (_strlen(b) - 1); i++)
				argv[j][i] = b[i];
			argv[j][i] = '\0';
		}
		else
			argv[j] = _strdup(b);
		b = strtok(NULL, " ");
		for (j = 1; j < matrix_size; j++)
		{
			if (j == matrix_size - 1)
			{argv[j] = (char *)malloc(sizeof(char) * _strlen(b));
				for (i = 0; i < (_strlen(b) - 1); i++)
					argv[j][i] = b[i];
				argv[j][i] = '\0'; }
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
		_path_handler(userinput, nlines);
}
