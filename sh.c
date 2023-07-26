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
/**
 * main - starting point
 * Return: 0 if Success
 */
int main(void)
{char *userinput = NULL;
ssize_t nlines = 0;
size_t nline = 0;
pid_t process_pid;
int inter_mode = isatty(STDIN_FILENO);
if (!inter_mode)
{	nlines = getline(&userinput, &nline, stdin);
	if (_strcmp(userinput, "exit") == 0)
		;
	else if (_strcmp(userinput, "env") == 0)
		_print_env();
	else
		sh_cmd(userinput, nlines); }
while (inter_mode)
{
	if (nlines != -1)
	{write(STDOUT_FILENO, "#cisfun$ ", 10);
	nlines = getline(&userinput, &nline, stdin); }
	if (nlines == -1)
	{
		if (feof(stdin))
		{write(STDOUT_FILENO, "\n", 1);
		break; }
		else
			break; }
	else if (_strcmp(userinput, "\n") == 0)
		;
	else if (_strcmp(userinput, "env") == 0)
		_print_env();
	else if (_strcmp(userinput, "exit") == 0)
		break;
	else
	{	process_pid = fork();
		if (process_pid == -1)
			perror("fork");
		else if (process_pid == 0)
		{	sh_cmd(userinput, nlines);
			nlines = -1; }
		else
			wait(NULL); } }
	free(userinput);
	return (0); }
