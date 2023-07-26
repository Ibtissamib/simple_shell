#include "shell.h"
/**
 * call_fork-if the command exists or not
 * @userinput: pointer to char
 * @n: ssize_t
 *
 * Return: Integer
 */
int call_fork(char *userinput, ssize_t n)
{
	ssize_t j = 0, matrix_size = 0, ncop;
	char *b, *cmd,  *path_cmd, *path, *copy_path, *s, *s_slash, *cop;
	int _call = 0;

	cop = _strdup(userinput);
	ncop = n;
	matrix_size = nbr_wrd(cop, ncop);
	b = strtok(cop, " ");
	if (j == matrix_size - 1)
		cmd = _decrem(b);
	else
		cmd = _strdup(b);
	if (access(cmd, F_OK) == 0)
		_call = 1;
	else
	{
		path = _getenv("PATH");
		copy_path = _strdup(path);
		path_cmd = strtok(copy_path, ":");
		s_slash = str_concat(path_cmd, "/");
		s = str_concat(s_slash, cmd);
		while (path_cmd != NULL)
		{
			if (access(s, F_OK) == 0)
			{	_call = 1;
				break; }
			path_cmd = strtok(NULL, ":");
			s_slash = str_concat(path_cmd, "/");
			s = str_concat(s_slash, cmd);
		}
	}
	return (_call);
}
